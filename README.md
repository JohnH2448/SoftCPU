# VenomCPU

## Introduction
VenomCPU is a RISC-V CPU core implementing the RV32I base ISA with Zicsr support, verified using the RISC-V Compatibility Framework (RISCOF). The core is provided as synthesizable SystemVerilog, and can be used in FPGA, as a reference implementation, a research and learning platform, or as a foundation for custom RISC-V system designs.

## Features

- RISC-V RV32I Zicsr ISA
- Verified Against Privileged RISCOF Test Suite
- In-Order 5-Stage Pipeline
- Decoupled Memory Interface for External RAM
- Hardwired M-Mode Execution

## Quickstart
All synthesizable SystemVerilog RTL for VenomCPU is contained in the `Core/` directory. To integrate the core, first clone the repository:
```bash
git clone https://github.com/JohnH2448/VenomCPU
```
The contents of `Core/` are fully self-contained and may be directly imported into FPGA or ASIC build flows. Other directories (simulation and verification artifacts) are not required for hardware integration. `Top.sv` is the hierarchical top-level module and serves as the compilation entry point for the core.

## Simulator
This SystemVerilog core comes with a corresponding simulator to more easily observe and test behavior. The simulation tool used is Verilator, which compiles HDL to native binaries. Verilator takes two input categories, HDL and a C++ test harness. The simulator included here is already compiled with a fixed test harness. To run the simulator with the default test harness, execute the command below from the repository root:
```bash
# Executes the simulator
./Verilator/VTop
```

For non-trivial debugging, a custom test harness may be necessary. To create a custom test harness and rebuild the simulator, you must have the Verilator CLI tool installed. From there, create a new file in the repository root `sim_main.cpp`. Refer to the Verilator documentation for guidance on writing a custom C++ test harness tailored to your specific needs. Once the file is complete, run the following commands:
```bash
# Version
Verilator 5.020 2024-01-01 rev (Debian 5.020-1)

# Produces a C program that simulates HDL
verilator -Wall -Wno-fatal --cc \
  Core/StaticPack.sv Core/ConfigPack.sv Core/Top.sv Core/Control/*.sv \
  Core/Pipeline/*.sv Core/Interface/*.sv \
  --top-module Top --exe sim_main.cpp \
  --Mdir Verilator

# Compiles the C program to an executable
export PATH=/usr/bin:/bin:$PATH
hash -r
make -C Verilator -f VTop.mk -j"$(nproc)"

# Executes the simulation
./Verilator/VTop
```
Any changes to the HDL require a full rebuild of both the C program and the executable. For edits to the test harness alone, only rebuilding the executable is necessary. Print statements may also exist in the outside of the test harness, and could hinder directed testing. **Ensure all $display and $strobe commands inside the HDL are removed** if a blank slate simulation is required. 

## Running Software
VenomCPU is capable of bare-metal firmware execution with complete machine-mode system support. The core has a configurable reset parameter `resetVector`, which sets the PC value on reset. This may be altered to point to any address in supported RAM. VenomCPU features RISC-V spec compliant exception handling, so machine mode runtime environments are recommended. These must be initialized by configuring CSRs in the boot sequence, usually `MTVEC` and `MSCRATCH` at a minimum. A full list of supported CSRs is included in this document. If uninitialized, the PC will be reset to 0 on any trap, which can cause unbreakable error loops.

If desired, the CPU can run entirely on user mode so long as an exception causing instruction is never detected. This is done by exclusively using instructions in the base RV32I ISA, usually without `SYSTEM` class instructions. On loop end, a jump instruction back to the beginning of the program will cause the software to run in an infinite loop. For simple software implimentations, this strategy is surprisingly powerful and easy to set up.

In simulation, the CPU initializes programs by reading `mem.hex` directly into RAM. This happens before any execution and is automatic. To run programs, compile them to `.hex` and paste them into the specified file. The first hex word is loaded into address 32'd0, the next into 32'd4, etc. For physical hardware implementations, whatever memory system feeds the PC will serve this role. The PC will grab the first word at the `resetVector` and begin stepping through instructions. Programs must be initialized via JTAG, flash, or some other similar method.

## Memory

(Be careful with this, as deviating from default memory has not been fully verified as of yet. This is near on the to-do list.)

VenomCPU uses a decoupled memory interface, allowing the core to operate with any external RAM implementation that conforms to the defined handshake protocol. The included LUTRAM/BRAM implementation in the `Core/` directory is intended for initial bring-up and simulation, but can be modified or replaced as needed.

The size of the default memory can be configured by adjusting the `memoryBytes` parameter in `ConfigPack.sv`. It is recommended to use a word-aligned, power-of-two depth depth to avoid invalid or unmapped address ranges.

If you choose to replace the default memory implementation, you may need to create a custom HDL memory harness that satisfies the required handshake behavior. The full protocol specification is provided in `Core/Interface/`. 

VenomCPU guarantees deterministic behavior and will strictly adhere to this interface contract. However, the core assumes standard synchronous setup and hold timing. When interfacing with asynchronous memory or memory operating in a separate clock domain, additional synchronization logic **must be implemented** in the harness to handle clock domain crossing and prevent metastability.

## Supported CSR Reference Table
| CSR       | ACCESS | NOTES                                 |
|-----------|--------|---------------------------------------|
| MSTATUS   | MRW    | Only MRW Bits 3 + 7. M-Mode Hardwired |
| MEPC      | MRW    | Word Align Mask                       |
| MCAUSE    | MRW    | Includes Misalignment Traps           |
| MTVAL     | MRW    | Standard                              |
| MIE       | MRW    | Only MRW Bits 3 + 7 + 11              |
| MTVEC     | MRW    | Word Align Mask + Direct Mode Only    |
| MSCRATCH  | MRW    | Standard                              |
| MISA      | MRO    | RV32I                                 |
| MVENDORID | MRO    | Standard                              |
| MARCHID   | MRO    | Standard                              |
| MIP       | MRW    | Writes Ignored But Don't Trap         |
| MCYCLE    | MRW    | Writes Override Hardware Increments   |
| MINSTRET  | MRW    | Writes Override Hardware Increments   |

## Development Roadmap
1. Fabric usage reduction, polish, and optimization (v1.0 is a rough draft)
2. Verification with randomized multi-cycle RAM
3. `memoryBytes` plumbing
4. Verification with constrained randomized tests
5. Load buffer with dependency checks
6. Hardware interrupt timer and spec accurate handling
7. FreeRTOS compatibility

## Licence
VenomCPU is fully open source and free to use under the project's license. You are welcome to use, modify, and integrate the core into your own projects. If you end up using VenomCPU, I’d love to hear about it — feedback and project showcases are always appreciated.


