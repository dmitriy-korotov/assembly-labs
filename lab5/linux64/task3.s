.data
 doubleFormatIn: .string "%lf"

 doubleFormatOut: .string "%lf\n"

.text
 .globl main

main:
 sub $8, %rsp
 sub $64, %rsp

 lea doubleFormatIn(%rip), %rdi
 lea (%rsp), %rsi
 mov $0, %al
 call scanf

 lea doubleFormatIn(%rip), %rdi
 lea 8(%rsp), %rsi
 mov $0, %al
 call scanf

 movsd 0(%rsp), %xmm0
 movsd 8(%rsp), %xmm1
 mov $0, %al
 call pow

 lea doubleFormatOut(%rip), %rdi
 mov $1, %al
 call printf

 add $72, %rsp
 xor %eax, %eax
 ret
