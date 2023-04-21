	.file	"test20.cc"
__SP_H__ = 0x3e
__SP_L__ = 0x3d
__SREG__ = 0x3f
__RAMPZ__ = 0x3b
__CCP__ = 0x34
__tmp_reg__ = 0
__zero_reg__ = 1
	.text
.global	_Z10init_timerv
	.type	_Z10init_timerv, @function
_Z10init_timerv:
/* prologue: function */
/* frame size = 0 */
/* stack size = 0 */
.L__stack_usage = 0
	ldi r30,lo8(16)
	ldi r31,lo8(11)
	st Z,__zero_reg__
	ldi r24,lo8(7)
	std Z+1,r24
	ldi r24,lo8(100)
	ldi r25,0
	std Z+12,r24
	std Z+13,r25
	ldd r24,Z+1
	ori r24,lo8(16)
	std Z+1,r24
	ldi r24,lo8(10)
	ldi r25,0
	std Z+12,r24
	std Z+13,r25
	ldi r30,lo8(96)
	ldi r31,lo8(4)
	ldi r24,lo8(-128)
	std Z+5,r24
	ldi r18,lo8(79999)
	ldi r19,hi8(79999)
	ldi r25,hlo8(79999)
1:	subi r18,1
	sbci r19,0
	sbci r25,0
	brne 1b
	rjmp .
	nop
	std Z+6,r24
	ldi r18,lo8(79999)
	ldi r19,hi8(79999)
	ldi r25,hlo8(79999)
1:	subi r18,1
	sbci r19,0
	sbci r25,0
	brne 1b
	rjmp .
	nop
	std Z+5,r24
	ldi r18,lo8(79999)
	ldi r19,hi8(79999)
	ldi r25,hlo8(79999)
1:	subi r18,1
	sbci r19,0
	sbci r25,0
	brne 1b
	rjmp .
	nop
	std Z+6,r24
	ldi r18,lo8(3999999)
	ldi r19,hi8(3999999)
	ldi r24,hlo8(3999999)
1:	subi r18,1
	sbci r19,0
	sbci r24,0
	brne 1b
	rjmp .
	nop
/* epilogue start */
	ret
	.size	_Z10init_timerv, .-_Z10init_timerv
.global	_Z10send_pulsev
	.type	_Z10send_pulsev, @function
_Z10send_pulsev:
/* prologue: function */
/* frame size = 0 */
/* stack size = 0 */
.L__stack_usage = 0
	ldi r30,lo8(96)
	ldi r31,lo8(4)
	ldi r24,lo8(2)
	std Z+5,r24
	ldi r26,lo8(9999)
	ldi r27,hi8(9999)
1:	sbiw r26,1
	brne 1b
	rjmp .
	nop
	std Z+6,r24
/* epilogue start */
	ret
	.size	_Z10send_pulsev, .-_Z10send_pulsev
.global	_Z13measure_pulsev
	.type	_Z13measure_pulsev, @function
_Z13measure_pulsev:
/* prologue: function */
/* frame size = 0 */
/* stack size = 0 */
.L__stack_usage = 0
	call _Z10send_pulsev
.L4:
	lds r24,1128
	sbrs r24,0
	rjmp .L4
	lds r18,2842
	lds r19,2842+1
.L5:
	lds r24,1128
	sbrc r24,0
	rjmp .L5
	lds r24,2842
	lds r25,2842+1
	sub r24,r18
	sbc r25,r19
/* epilogue start */
	ret
	.size	_Z13measure_pulsev, .-_Z13measure_pulsev
.global	_Z13update_summerj
	.type	_Z13update_summerj, @function
_Z13update_summerj:
/* prologue: function */
/* frame size = 0 */
/* stack size = 0 */
.L__stack_usage = 0
	movw r18,r24
	subi r24,100
	sbc r25,__zero_reg__
	cpi r24,100
	cpc r25,__zero_reg__
	brsh .L10
	ldi r24,lo8(50)
	ldi r25,0
	sts 2844,r24
	sts 2844+1,r25
	ldi r18,lo8(399999)
	ldi r19,hi8(399999)
	ldi r24,hlo8(399999)
1:	subi r18,1
	sbci r19,0
	sbci r24,0
	brne 1b
	rjmp .
	nop
	ldi r24,lo8(-128)
	sts 1125,r24
	ldi r25,lo8(399999)
	ldi r30,hi8(399999)
	ldi r31,hlo8(399999)
1:	subi r25,1
	sbci r30,0
	sbci r31,0
	brne 1b
.L16:
	rjmp .
	nop
.L15:
	sts 1126,r24
/* epilogue start */
	ret
.L10:
	movw r24,r18
	subi r24,75
	sbc r25,__zero_reg__
	sbiw r24,25
	brsh .L12
	ldi r24,lo8(25)
	ldi r25,0
	sts 2844,r24
	sts 2844+1,r25
	ldi r18,lo8(239999)
	ldi r19,hi8(239999)
	ldi r24,hlo8(239999)
1:	subi r18,1
	sbci r19,0
	sbci r24,0
	brne 1b
	rjmp .
	nop
	ldi r24,lo8(-128)
	sts 1125,r24
	ldi r25,lo8(239999)
	ldi r30,hi8(239999)
	ldi r31,hlo8(239999)
1:	subi r25,1
	sbci r30,0
	sbci r31,0
	brne 1b
	rjmp .L16
.L12:
	movw r24,r18
	sbiw r24,25
	sbiw r24,25
	brsh .L13
	ldi r24,lo8(10)
	ldi r25,0
	sts 2844,r24
	sts 2844+1,r25
	ldi r18,lo8(79999)
	ldi r19,hi8(79999)
	ldi r24,hlo8(79999)
1:	subi r18,1
	sbci r19,0
	sbci r24,0
	brne 1b
	rjmp .
	nop
	ldi r24,lo8(-128)
	sts 1125,r24
	ldi r25,lo8(79999)
	ldi r30,hi8(79999)
	ldi r31,hlo8(79999)
1:	subi r25,1
	sbci r30,0
	sbci r31,0
	brne 1b
	rjmp .L16
.L13:
	subi r18,1
	sbc r19,__zero_reg__
	cpi r18,24
	cpc r19,__zero_reg__
	brsh .L14
	ldi r24,lo8(90)
	ldi r25,0
	sts 2844,r24
	sts 2844+1,r25
	ldi r24,lo8(-15537)
	ldi r25,hi8(-15537)
1:	sbiw r24,1
	brne 1b
	rjmp .
	nop
	ldi r24,lo8(-128)
	sts 1125,r24
	ldi r30,lo8(-15537)
	ldi r31,hi8(-15537)
1:	sbiw r30,1
	brne 1b
	rjmp .L16
.L14:
	sts 2844,__zero_reg__
	sts 2844+1,__zero_reg__
	ldi r24,lo8(-128)
	rjmp .L15
	.size	_Z13update_summerj, .-_Z13update_summerj
	.section	.text.startup,"ax",@progbits
.global	main
	.type	main, @function
main:
/* prologue: function */
/* frame size = 0 */
/* stack size = 0 */
.L__stack_usage = 0
	ldi r24,lo8(-126)
	sts 1121,r24
	ldi r24,lo8(1)
	sts 1122,r24
	call _Z10init_timerv
	ldi r28,lo8(58)
	ldi r29,0
.L18:
	call _Z13measure_pulsev
	movw r22,r28
	call __udivmodhi4
	movw r24,r22
	call _Z13update_summerj
	rjmp .L18
	.size	main, .-main
	.ident	"GCC: (GNU) 12.2.0"
