`timescale 1 ns/100 ps

module t_add4;
reg a,b,cin;      // Inputs are registers
wire sum,carry;   // Outputs are wires

fulladder uut(a,b,cin,sum,carry);

initial begin
a = 1'b0; b = 1'b0; cin = 1'b0;

#40 a = 1'b0; b = 1'b0; cin = 1'b1;

#40 a = 1'b0; b = 1'b1; cin = 1'b0;

#40 a = 1'b0; b = 1'b1; cin = 1'b1;

#40 a = 1'b1; b = 1'b0; cin = 1'b0;

#40 a = 1'b1; b = 1'b0; cin = 1'b1;

#40 a = 1'b1; b = 1'b1; cin = 1'b0;

#40 a = 1'b1; b = 1'b1; cin = 1'b1;

end

initial #320 $finish();
                
endmodule