// Copyright 2026 FER, HPC Architecture and Application Research Center
// SPDX-License-Identifier: Apache-2.0 WITH SHL-2.1
//
// Licensed under the Solderpad Hardware License v 2.1 (the "License");
// you may not use this file except in compliance with the License, or,
// at your option, the Apache License version 2.0.
// You may obtain a copy of the License at https://solderpad.org/licenses/SHL-2.1/
//
// Emil Popovic <mail@emilpopovic.me>

// Reset replica to break up a high fanout reset tree
(* keep *)
(* keep_hierarchy *)
module vernii_rst_replica (
    input  logic clk_i,
    input  logic rst_ni,
    output logic rst_no
);

logic rst_nq;

always_ff @(posedge clk_i or negedge rst_ni) begin
    if (!rst_ni) rst_nq <= 1'b0;
    else         rst_nq <= 1'b1;
end

assign rst_no = rst_nq;

endmodule
