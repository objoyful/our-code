`timescale 1 ns/100 ps

module fulladder (
    input a,b,cin,
    output sum,carry
);

wire w1,w2,w3,w4;       //Internal connections

xor #10 (w1,a,b);
xor #10 (sum,w1,cin);        //Sum output = a ^ b ^ cin (^ is xor)


and #10 (w2,a,b);               // 10 unit of delay for every gate
and #10 (w3,b,cin);
and #10 (w4,cin,a);

or  #10 (carry,w2,w3,w4);     //carry output = a.b + b.cin + a.cin

// Total max delay should be 30, we take 40 in testbench for safety
endmodule