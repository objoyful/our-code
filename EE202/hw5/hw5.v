`timescale 1 ns/100 ps
module hw5circuit(F, x, y, z);
  output F;
  input x, y, z;
  wire w1, w2;
  
  and #(10) A1(w1, x, z);
  not #(5) N1(w2, w1);
  and #(10) A2(F, w2, y);
endmodule // hw5circuit