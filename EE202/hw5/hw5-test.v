`timescale 1 ns/100 ps

module hw5_test;
reg x, y, z;
wire F;

hw5circuit c1(F, x, y, z);

initial begin
    x = 1'b0; y = 1'b0; z = 1'b0;
    #30 x=1'b0; y=1'b0; z=1'b1;
    #30 x=1'b0; y=1'b1; z=1'b0;
    #30 x=1'b0; y=1'b1; z=1'b1;
    #30 x=1'b1; y=1'b0; z=1'b0;
    #30 x=1'b1; y=1'b0; z=1'b1;
    #30 x=1'b1; y=1'b1; z=1'b0;
    #30 x=1'b1; y=1'b1; z=1'b1;

end

initial #300 $finish;
endmodule // hw5_test