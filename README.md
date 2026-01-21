# VenomCPU
## RISC-V RV32I Pipelined CPU Core in SystemVerilog
### RISCOF verification in progress. Docs will drop alongside the first verified release!
### Specifications:
- In-Order 5-Stage Pipeline
- Handshake Based IF + MEM For Arbitrary External RAM
- M-Mode Privilaged ISA
- Zicsr (CSR Decode Package)
- RV32I Base Integer Instruction Set

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
| MARCHID   | MRO    | Stadard                               |
| MIP       | MRW    | Writes Ignored But Don't Trap         |
| MCYCLE    | MRW    | Writes Override Hardware Incriments   |
| MINSTRET  | MRW    | Writes Override Hardware Incriments   |

Pipeline Diagram: 

