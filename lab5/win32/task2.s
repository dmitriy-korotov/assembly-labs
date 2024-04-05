.data
.LC0:
        .string "%hd"
.LC1:
        .string "%d"
.LC2:
        .string "%lld"
.LC3:
        .string "%f"
.LC4:
        .string "%lf"
.LC5:
        .string "%hd\n"
.LC6:
        .string "%d\n"
.LC7:
        .string "%lld\n"
.LC8:
        .string "%f\n"
.LC9:
        .string "%lf\n"

.text
.globl _main

_main:
        leal    4(%esp), %ecx
        andl    $-16, %esp
        pushl   -4(%ecx)
        pushl   %ebp
        movl    %esp, %ebp
        pushl   %ecx
        leal    -34(%ebp), %eax
        subl    $44, %esp

        pushl   %eax
        pushl   $.LC0
        call    _scanf
        popl    %eax

        leal    -32(%ebp), %eax
        popl    %edx
        pushl   %eax
        pushl   $.LC1
        call    _scanf
        popl    %ecx
        popl    %eax


        leal    -24(%ebp), %eax
        pushl   %eax
        pushl   $.LC2
        call    _scanf
        popl    %eax
        leal    -28(%ebp), %eax
        popl    %edx

        pushl   %eax
        pushl   $.LC3
        call    _scanf
        popl    %ecx
        popl    %eax


        leal    -16(%ebp), %eax
        pushl   %eax
        pushl   $.LC4
        call    _scanf
        popl    %eax
        
        movswl  -34(%ebp), %eax

        popl    %edx
        pushl   %eax
        pushl   $.LC5
        call    _printf
        popl    %ecx
        popl    %eax

        pushl   -32(%ebp)
        pushl   $.LC6
        call    _printf
        addl    $12, %esp

        pushl   -20(%ebp)
        pushl   -24(%ebp)
        pushl   $.LC7
        call    _printf

        flds    -28(%ebp)
        movl    $.LC8, (%esp)
        fstpl   4(%esp)
        call    _printf
        addl    $12, %esp

        pushl   -12(%ebp)
        pushl   -16(%ebp)
        pushl   $.LC9
        call    _printf
        movl    -4(%ebp), %ecx
        addl    $16, %esp

        leal    -4(%ecx), %esp
        xorl    %eax, %eax
        ret
