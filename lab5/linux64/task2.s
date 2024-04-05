.data
 shortFormatIn: .string "%hd"
 intFormatIn: .string "%d"
 longFormatIn: .string "%lld"
 floatFormatIn: .string "%lf"
 doubleFormatIn: .string "%lf"

 shortFormatOut: .string "%hd\n"
 intFormatOut: .string "%d\n"
 longFormatOut: .string "%lld\n"
 floatFormatOut: .string "%lf\n"
 doubleFormatOut: .string "%lf\n"

.text
 .globl main

main:
 sub $8, %rsp
 sub $64, %rsp

 lea shortFormatIn(%rip), %rdi
 lea (%rsp), %rsi
 mov $0, %al
 call scanf

 lea intFormatIn(%rip), %rdi
 lea 8(%rsp), %rsi
 mov $0, %al
 call scanf

 lea longFormatIn(%rip), %rdi
 lea 16(%rsp), %rsi
 mov $0, %al
 call scanf

 lea floatFormatIn(%rip), %rdi
 lea 24(%rsp), %rsi
 mov $0, %al
 call scanf

 lea doubleFormatIn(%rip), %rdi
 lea 32(%rsp), %rsi
 mov $0, %al
 call scanf




 lea shortFormatOut(%rip), %rdi
 mov (%rsp), %rsi
 mov $0, %al
 call printf

 lea intFormatOut(%rip), %rdi
 mov 8(%rsp), %rsi
 mov $0, %al
 call printf

 lea longFormatOut(%rip), %rdi
 mov 16(%rsp), %rsi
 mov $0, %al
 call printf

 lea floatFormatOut(%rip), %rdi
 movsd 24(%rsp), %xmm0
 mov $1, %al
 call printf

 lea doubleFormatOut(%rip), %rdi
 movsd 32(%rsp), %xmm0
 mov $1, %al
 call printf

 add $72, %rsp
 xor %eax, %eax
 ret
