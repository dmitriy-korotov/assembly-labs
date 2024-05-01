.data
.text
.globl Calculate

Calculate: # double Calculate(double a, double b)
 sub $8, %rsp
 vsubsd %xmm1, %xmm0, %xmm0
 add $8, %rsp
 ret
