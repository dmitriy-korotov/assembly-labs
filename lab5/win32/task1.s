.data
 msg:
  .string "PIN-22 team-3 Krinitskiy Alexander, Korotov Dmitriy\n"

.text
.globl _main

_main:
 sub $12, %esp
 pushl $msg

 call _puts
 add $4, %esp
 add $12, %esp
 xor %eax, %eax
 ret
