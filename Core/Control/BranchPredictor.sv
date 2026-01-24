import StaticPack::*;
import ConfigPack::*;

module BranchPredictor (
    input logic clock,
    input logic reset,
    output logic [31:0] branchPredictData,
    output logic branchPredictValid
);

    // Simple static predictor: always not taken
    assign branchPredictValid = 1'b0;
    assign branchPredictData = 32'd0;

endmodule
