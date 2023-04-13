	.file	"test13.cc"
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
	sts 327,__zero_reg__
.L2:
	lds r24,321
	sbrc r24,2
	rjmp .L2
	ldi r24,lo8(-86)
	ldi r25,lo8(42)
	sts 330,r24
	sts 330+1,r25
.L3:
	lds r24,321
	sbrc r24,0
	rjmp .L3
	ldi r24,lo8(1)
	sts 320,r24
	ldi r24,lo8(4)
	sts 1156,r24
	ldi r25,lo8(1)
	ldi r24,lo8(12)
.L4:
	lds r18,323
	sbrs r18,0
	rjmp .L4
	sts 323,r25
	sts 1159,r24
	rjmp .L4
	.size	main, .-main
	.ident	"GCC: (GNU) 12.2.0"
