import pack::*;

module BranchPredictor (
    input logic clock,
    input logic reset,
    input logic [31:0] branchPredictData,
    input logic branchPredictValid
);

    // Simple static predictor: always not taken
    assign branchValid = 1'b0;
    assign branchData = 32'd0;

endmodule