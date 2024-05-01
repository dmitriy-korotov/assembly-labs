.data
    fmt: 
        .string "a = %d\nb = %d\nc = %d\nd = %d\ne = %d\nf = %d\ng = %d\n"
.text
.globl Print

Print: # int Print(int a, int b, int c, int d, int e, int f, int g)
 push %rsi
 push 16(%rsp)
 push %r9

 mov %r8, %r9
 mov %rcx, %r8
 mov %rdx, %rcx
 mov %rsi, %rdx
 mov %rdi, %rsi

 lea fmt(%rip), %rdi
 xor %al, %al
 call printf

 pop %r9
 add $8, %rsp
 pop %rax
 ret
