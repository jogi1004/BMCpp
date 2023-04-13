	.file	"test10.cc"
__SP_H__ = 0x3e
__SP_L__ = 0x3d
__SREG__ = 0x3f
__RAMPZ__ = 0x3b
__CCP__ = 0x34
__tmp_reg__ = 0
__zero_reg__ = 1
	.text
	.section	.text.startup,"ax",@progbits
.global	main
	.type	main, @function
main:
/* prologue: function */
/* frame size = 0 */
/* stack size = 0 */
.L__stack_usage = 0
	ldi r24,lo8(12)
	sts 1152,r24
	ldi r24,lo8(4)
	sts 1157,r24
	ldi r24,lo8(12)
.L2:
	ldi r18,lo8(79999)
	ldi r19,hi8(79999)
	ldi r25,hlo8(79999)
1:	subi r18,1
	sbci r19,0
	sbci r25,0
	brne 1b
	rjmp .
	nop
	sts 1159,r24
	rjmp .L2
	.size	main, .-main
	.ident	"GCC: (GNU) 12.2.0"
