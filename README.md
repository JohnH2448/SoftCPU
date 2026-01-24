# VenomCPU
## RISC-V RV32I Pipelined CPU Core in SystemVerilog
### RISCOF verification in progress. Docs will drop alongside the first verified release!
### Specifications:
- In-Order 5-Stage Pipeline
- Handshake Based IF + MEM For Arbitrary External RAM
- Precise Trap Behavior
- Zicsr + M-Mode Privileged ISA
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

# SoftCPU RTL Structure

```mermaid
%%{init: {"flowchart": {"curve": "stepAfter", "nodeSpacing": 10, "rankSpacing": 40}}}%%
flowchart LR
    %% Styles
    classDef plain fill:#fff,stroke:#000,stroke-width:2px;
    classDef input fill:#eee,stroke:#000,stroke-dasharray: 5 5;
    
    %% Inputs
    Clock[Clock]:::input
    Reset[Reset]:::input
    Interrupt[Interrupt]:::input

    %% Main Structure
    subgraph Core
        direction LR
        
        %% Pipeline Stages
        Fetch[Fetch Stage]:::plain
        Decode[Decode Stage]:::plain
        Execute[Execute Stage]:::plain
        Memory[Memory Stage]:::plain
        Writeback[Writeback Stage]:::plain
        
        %% Storage & Control
        RegFile[[Register File]]:::plain
        CSRFile[[CSR File]]:::plain
        BranchPred([Branch Predictor]):::plain
        Hazard{Hazard Unit}:::plain
        Forward{Forwarding}:::plain

        %% Pipeline Flow
        Fetch --> Decode
        Decode --> Execute
        Execute --> Memory
        Memory --> Writeback

        %% Fetch Interactions
        Clock & Reset & Interrupt --> Fetch
        BranchPred --> Fetch
        Execute -- Branch Info --> Fetch
        Hazard -- Stall/Flush --> Fetch

        %% Decode Interactions
        Fetch --> Hazard
        Decode -- Control --> Hazard
        Decode <--> RegFile
        Hazard -- Stall/Flush --> Decode

        %% Execute Interactions
        Decode --> Execute
        Execute -- Control --> Hazard
        Execute -- Data --> Forward
        Execute --> BranchPred
        Forward --> Execute
        Hazard -- Stall/Flush --> Execute

        %% Memory Interactions
        Execute --> Memory
        Memory -- Control --> Hazard
        Memory -- Data --> Forward
        Hazard -- Stall/Flush --> Memory

        %% Writeback Interactions
        Memory --> Writeback
        Writeback --> RegFile
        Writeback --> TopCSR[Wrapper/CSR]
        Writeback --> Forward
        
        %% Side Units
        CSRFile <--> TopCSR 
        
        %% Mem wrapper visualization
        subgraph MemInterface [.]
            direction TB
            DMem[Memory]
        end
        
        Fetch <--> DMem
        Memory <--> DMem
    end
```


