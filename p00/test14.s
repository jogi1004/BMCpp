	.file	"test14.cc"
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
.L4:
	lds r25,323
	sbrs r25,0
	rjmp .L4
	sts 323,r24
	rjmp .L4
	.size	main, .-main
	.ident	"GCC: (GNU) 12.2.0"
