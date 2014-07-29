.data
integer: .word 4
.text
.globl main
main:
addi $v0, $zero, 5 # read integer
syscall
li $s2, 3 # put s2=3
li $s3, 2 #     s3=2
mult $v0, $s2 # $t1 = v0 * 3
mflo $t1
div $v0, $s3 # s0 = v0 / 2
mflo $s0
add $s1, $t1, $s0
xor $v0, $v0, $v0
addi $v0, $zero, 1
add $a0, $zero, $s1
syscall
li $v0, 10 #exit
syscall