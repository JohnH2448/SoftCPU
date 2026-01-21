from elftools.elf.elffile import ELFFile

# Harvard model bases (as your RTL expects)
IMEM_BASE = 0x00000000
DMEM_BASE = 0x80000000

# Your RTL effectively uses address[15:0] for indexing
ADDR_MASK = 0xFFFF

# Default fill values (recommend: IMEM NOP, DMEM 0)
IMEM_DEFAULT_WORD = 0x00000013
DMEM_DEFAULT_WORD = 0x00000000

elf_name = input("ELF file: ").strip()

imem = {}
dmem = {}

def write_words(mem, base, addr, data, label=""):
    """
    Write bytes into word-addressed memory dict using:
      idx = (((addr - base) & ADDR_MASK) >> 2)
    This matches RTL that truncates to address[15:0].
    """
    off = (addr - base) & ADDR_MASK

    if off % 4 != 0:
        raise Exception(
            f"Unaligned write: {label} addr=0x{addr:08X} base=0x{base:08X} off=0x{off:04X}"
        )

    # pad to whole words
    if len(data) % 4:
        data += b"\x00" * (4 - (len(data) % 4))

    idx = off // 4
    for i in range(0, len(data), 4):
        w = data[i] | (data[i+1] << 8) | (data[i+2] << 16) | (data[i+3] << 24)

        # Detect collisions caused by address[15:0] wrap
        if idx in mem and mem[idx] != w:
            raise Exception(
                f"Address collision ({label}): "
                f"addr=0x{addr:08X} maps to word idx {idx} (off=0x{off:04X}), "
                f"existing=0x{mem[idx]:08X}, new=0x{w:08X}"
            )

        mem[idx] = w
        idx += 1
        off = (off + 4) & ADDR_MASK
        addr += 4

def dump_hex(name, mem, default_word):
    """
    Dumps 32-bit words line-by-line.
    Writes from word 0 up to max written word, filling gaps with default_word.
    """
    if not mem:
        open(name, "w").close()
        return

    max_i = max(mem.keys())
    with open(name, "w") as f:
        for i in range(max_i + 1):
            f.write(f"{mem.get(i, default_word):08X}\n")

TEXT_PREFIXES = (".text", ".text.init", ".init", ".text.startup")
DMEM_PREFIXES = (".data", ".bss", ".sbss", ".sdata", ".rodata", ".tohost", ".fromhost")

with open(elf_name, "rb") as f:
    elf = ELFFile(f)

    for sec in elf.iter_sections():
        name = sec.name
        sh = sec.header

        # Skip empty or non-mapped sections
        if sh.sh_size == 0:
            continue
        addr = sh.sh_addr
        if addr == 0:
            continue

        # Pull section bytes; zero-fill NOBITS (BSS)
        if sh.sh_type == "SHT_NOBITS":
            data = b"\x00" * sh.sh_size
        else:
            data = sec.data()

        # Route by section name
        if name.startswith(TEXT_PREFIXES):
            # Text is linked at 0x8000_0000 but lives in IMEM starting at 0.
            # So rebase by subtracting DMEM_BASE (0x8000_0000).
            imem_addr = addr - DMEM_BASE
            write_words(imem, IMEM_BASE, imem_addr, data, label=f"IMEM {name}")
        elif name.startswith(DMEM_PREFIXES):
            write_words(dmem, DMEM_BASE, addr, data, label=f"DMEM {name}")
        else:
            # Default: treat unknown mapped sections as DMEM
            write_words(dmem, DMEM_BASE, addr, data, label=f"DMEM {name}")

dump_hex("imem.hex", imem, IMEM_DEFAULT_WORD)
dump_hex("dmem.hex", dmem, DMEM_DEFAULT_WORD)

print("Done -> imem.hex  dmem.hex")
