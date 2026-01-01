// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Primary model header
//
// This header should be included by all source files instantiating the design.
// The class here is then constructed to instantiate the design.
// See the Verilator manual for examples.

#ifndef VERILATED_VTOP_H_
#define VERILATED_VTOP_H_  // guard

#include "verilated.h"

class VTop__Syms;
class VTop___024root;

// This class is the main interface to the Verilated model
class alignas(VL_CACHE_LINE_BYTES) VTop VL_NOT_FINAL : public VerilatedModel {
  private:
    // Symbol table holding complete model state (owned by this class)
    VTop__Syms* const vlSymsp;

  public:

    // PORTS
    // The application code writes and reads these signals to
    // propagate new values into/out from the Verilated model.
    VL_IN8(&clock,0,0);
    VL_IN8(&reset,0,0);
    VL_IN8(&__SYM__interrupt,0,0);
    VL_OUT8(&dbg_IF_ID_Valid,0,0);
    VL_OUT8(&dbg_ID_EX_Valid,0,0);
    VL_OUT8(&dbg_EX_MEM_Valid,0,0);
    VL_OUT8(&dbg_MEM_WB_Valid,0,0);
    VL_OUT8(&dbg_trap,0,0);
    VL_OUT8(&dbg_IMEM_valid,0,0);
    VL_OUT8(&forwardEnable1,0,0);
    VL_OUT8(&forwardEnable2,0,0);
    VL_OUTW(&dbg_registers,1023,0,32);
    VL_OUT(&dbg_IF_ID_programCounter,31,0);
    VL_OUT(&dbg_IF_ID_instruction,31,0);
    VL_OUT(&dbg_ID_EX_programCounter,31,0);
    VL_OUT(&dbg_EX_MEM_programCounter,31,0);
    VL_OUT(&dbg_MEM_WB_programCounter,31,0);
    VL_OUT(&dbg_IMEM_data,31,0);
    VL_OUT(&dbg_pc,31,0);
    VL_OUT(&dbg_wb_value,31,0);
    VL_OUT(&forwardData1,31,0);
    VL_OUT(&forwardData2,31,0);

    // CELLS
    // Public to allow access to /* verilator public */ items.
    // Otherwise the application code can consider these internals.

    // Root instance pointer to allow access to model internals,
    // including inlined /* verilator public_flat_* */ items.
    VTop___024root* const rootp;

    // CONSTRUCTORS
    /// Construct the model; called by application code
    /// If contextp is null, then the model will use the default global context
    /// If name is "", then makes a wrapper with a
    /// single model invisible with respect to DPI scope names.
    explicit VTop(VerilatedContext* contextp, const char* name = "TOP");
    explicit VTop(const char* name = "TOP");
    /// Destroy the model; called (often implicitly) by application code
    virtual ~VTop();
  private:
    VL_UNCOPYABLE(VTop);  ///< Copying not allowed

  public:
    // API METHODS
    /// Evaluate the model.  Application must call when inputs change.
    void eval() { eval_step(); }
    /// Evaluate when calling multiple units/models per time step.
    void eval_step();
    /// Evaluate at end of a timestep for tracing, when using eval_step().
    /// Application must call after all eval() and before time changes.
    void eval_end_step() {}
    /// Simulation complete, run final blocks.  Application must call on completion.
    void final();
    /// Are there scheduled events to handle?
    bool eventsPending();
    /// Returns time at next time slot. Aborts if !eventsPending()
    uint64_t nextTimeSlot();
    /// Trace signals in the model; called by application code
    void trace(VerilatedVcdC* tfp, int levels, int options = 0);
    /// Retrieve name of this model instance (as passed to constructor).
    const char* name() const;

    // Abstract methods from VerilatedModel
    const char* hierName() const override final;
    const char* modelName() const override final;
    unsigned threads() const override final;
    /// Prepare for cloning the model at the process level (e.g. fork in Linux)
    /// Release necessary resources. Called before cloning.
    void prepareClone() const;
    /// Re-init after cloning the model at the process level (e.g. fork in Linux)
    /// Re-allocate necessary resources. Called after cloning.
    void atClone() const;
};

#endif  // guard
