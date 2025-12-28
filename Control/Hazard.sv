import pack::*;

module Hazard (
    input logic clock,
    input logic reset,
    input logic decodeExecuteValid,
    input logic decodeExecuteIllegal,
    input logic memoryWritebackValid,
    input logic memoryWritebackIllegal,
    input logic branchValid,
    input logic stallControl,
    output control fetchDecodeControl,
    output control decodeExecuteControl,
    output control executeMemoryControl,
    output control memoryWritebackControl,
    output logic controlReset
);
    // Trap Handler
    always_comb begin
        fetchDecodeControl = '0;
        decodeExecuteControl = '0;
        executeMemoryControl = '0;
        memoryWritebackControl = '0;
        controlReset = 1'b0;
        if (!reset) begin
            if (decodeExecuteValid && decodeExecuteIllegal) begin
                // Trap from Decode stage
                fetchDecodeControl.flush = 1'b1;
                decodeExecuteControl.flush = 1'b1;
                executeMemoryControl.flush = 1'b1;
                controlReset = 1'b1;
            end else if (memoryWritebackValid && memoryWritebackIllegal) begin
                // Trap from Memory stage
                fetchDecodeControl.flush = 1'b1;
                decodeExecuteControl.flush = 1'b1;
                executeMemoryControl.flush = 1'b1;
                memoryWritebackControl.flush = 1'b1;
                controlReset = 1'b1;
            end else if (branchValid) begin
                // PC Redirect Flush
                fetchDecodeControl.flush = 1'b1;
                decodeExecuteControl.flush = 1'b1;
            end
            if (stallControl) begin
                fetchDecodeControl.stall = 1'b1;
                decodeExecuteControl.stall = 1'b1;
                executeMemoryControl.stall = 1'b1;
                memoryWritebackControl.stall = 1'b1;
            end
        end
    end
    // almost done but add RAW



endmodule

// ================================================================
// HAZARD UNIT: WHAT IT MUST DO (SIMPLE, FOR YOUR CURRENT PIPELINE)
// ================================================================
//
// Your stages already:
// - Fetch: stalls itself when instructionDataValid=0 (bubbles via valid=0)
// - Execute: produces branchValid/branchData (redirect target)
// - Memory: produces stallControl when DMEM op is waiting
// - Decode/Memory: set `illegal` bits in payloads
//
// Therefore the hazard unit only needs to do FOUR things:
//
// ------------------------------------------------
// (1) TRAP ON ILLEGAL (HIGHEST PRIORITY)
// ------------------------------------------------
// Inputs:
//   - trap_valid  (stage_valid && stage_illegal)  // wherever you raise illegal
//   - trap_pc     (PC of trapping instruction)    // if you track it
//   - trap_vector (handler address, constant or CSR)
//
// Actions:
//   - Redirect PC to trap_vector
//   - Flush ALL YOUNGER instructions behind the trapping instruction
//     (at minimum: flush Fetch→Decode and Decode→Execute so no wrong work runs)
//   - Ensure trapping instruction is the one that causes the redirect (precise)
//
// Notes:
//   - Trap redirect must override branch redirects and all stalls.
//   - While trap is being taken, do not allow younger instructions to commit.
//
// ------------------------------------------------
// (2) FLUSH ON CONTROL REDIRECT (BRANCH/JAL/JALR)
// ------------------------------------------------
// Input:
//   - branchValid (from Execute)
//
// Actions (if not trapping this cycle):
//   - Flush younger stages (at minimum: FD and DE pipeline regs)
//   - Let Fetch use branchData to update PC (you already do this)
//
// Notes:
//   - Flush is required because Fetch may already have wrong-path instructions
//     sitting in FD/DE when branchValid asserts.
//
// ------------------------------------------------
// (3) GLOBAL STALL ON DMEM WAIT (BACKPRESSURE)
// ------------------------------------------------
// Input:
//   - mem_wait = stallControl (from Memory)
//
// Actions (if not trapping and not flushing for redirect):
//   - Stall earlier pipeline registers so the in-flight load/store completes:
//       stall FD, stall DE, stall EM
//   - Do NOT "advance" any younger instruction while mem_wait is true.
//
// Notes:
//   - Memory already computed the wait; hazard unit just propagates it.
//
// ------------------------------------------------
// (4) RAW CORRECTNESS (STALL + BUBBLE)  [NO/FULL FORWARDING DEPENDENT]
// ------------------------------------------------
// Inputs (minimal):
//   - ID consumer: id_valid, id_rs1, id_rs2   (your readAddress1/2)
//   - Producer tracking: ex_valid/ex_rd/ex_writes/ex_is_load,
//                        mem_valid/mem_rd/mem_writes,
//                        (optional) wb_valid/wb_rd/wb_writes
//
// Actions (if not trapping, not redirecting, not mem_wait):
//   - If ID reads a register that an older instruction will write
//     and the value is not yet available to the consumer:
//       * Stall IF and ID (hold consumer in Decode)
//       * Insert a bubble into EX for 1 cycle (invalidate DE->EX payload)
//         so the producer can continue moving forward.
//
// Notes:
//   - Always ignore x0 (rd==0 never creates a hazard).
//   - If you later add sufficient forwarding + write-first RF,
//     this simplifies mostly to just "load-use" stall.
//
// ------------------------------------------------
// PRIORITY ORDER (MUST MATCH CONTROL)
// ------------------------------------------------
// 1) Trap on illegal          (flush + redirect to trap vector)
// 2) Branch/jump redirect     (flush younger + redirect)
// 3) DMEM wait backpressure   (stall pipeline behind MEM)
// 4) RAW stall + bubble       (data dependency handling)
//
// ================================================================
