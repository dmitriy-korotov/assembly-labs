.data
 msg:
  .string "PIN-22 team-geys Krinitskiy Alexander, Korotov Dmitriy\n"

.text
.globl main

main:
 sub $8, %rsp

 lea msg(%rip), %rdi      # address of msg -> %rdi
 xor %al, %al             # %al=0 (there is no variable %xmm parameters)

 call puts

 add $8, %rsp
 xor %eax, %eax
 ret
