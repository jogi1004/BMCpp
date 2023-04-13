	.file	"test21.cc"
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
	ldi r24,lo8(-128)
	sts 1121,r24
.L2:
	sts 1125,r24
	ldi r18,lo8(399999)
	ldi r19,hi8(399999)
	ldi r25,hlo8(399999)
1:	subi r18,1
	sbci r19,0
	sbci r25,0
	brne 1b
	rjmp .
	nop
	sts 1126,r24
	ldi r18,lo8(399999)
	ldi r19,hi8(399999)
	ldi r25,hlo8(399999)
1:	subi r18,1
	sbci r19,0
	sbci r25,0
	brne 1b
	rjmp .
	nop
	rjmp .L2
	.size	main, .-main
	.ident	"GCC: (GNU) 12.2.0"
