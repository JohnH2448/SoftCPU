# VenomCPU
## RISC-V RV32I Pipelined CPU Core in SystemVerilog
### This is ~1-2 weeks from being verified. full docs will drop then!
### Free to use, just email me at jch0100@uah.edu
### README is very unpolished 
### DO NOT USE prototype versions. they are not verified
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
| MEPC      | MRW    | Permenant [1:0] Word Align Mask       |
| MCAUSE    | MRW    | Includes Misalignment Traps           |
| MTVAL     | MRW    | Standard                              |
| MIE       | MRW    | Only MRW Bits 3 + 7 + 11              |
| MTVEC     | MRW    | Permenant [1:0] Word Align Mask       |
| MSCRATCH  | MRW    | Standard                              |
| MISA      | MRO    | RV32I                                 |
| MVENDORID | MRO    | Standard                              |
| MARCHID   | MRO    | Stadard                               |
| MIP       | MRW    | Writes Ignored But Don't Trap         |
| MCYCLE    | MRW    | Writes Override Hardware Incriments   |
| MINSTRET  | MRW    | Writes Override Hardware Incriments   |

Pipeline Diagram: 
<img width="744" height="567" alt="image" src="https://github.com/user-attachments/assets/64defca3-998c-4ff6-a73f-742df615bb44" />
