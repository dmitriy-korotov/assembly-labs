.data
.text
.globl Calculate

Calculate: # int Calculate(int a, int b)
 sub $8, %rsp
 lea -113(%edi, %esi, 2), %eax
 add $8, %rsp
 ret
