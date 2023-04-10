	.file	"test00.cc"
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
	ldi r24,0
	ldi r30,lo8(a)
	ldi r31,hi8(a)
.L2:
	ld r25,Z+
	add r24,r25
	ldi r25,hi8(a+10)
	cpi r30,lo8(a+10)
	cpc r31,r25
	brne .L2
	ldi r25,0
/* epilogue start */
	ret
	.size	main, .-main
.global	a
	.section .bss
	.type	a, @object
	.size	a, 10
a:
	.zero	10
	.ident	"GCC: (GNU) 12.2.0"
.global __do_clear_bss
