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
	std Z+13,__zero_reg__
	ldi r24,lo8(100)
	std Z+12,r24
	ldi r24,lo8(16)
	std Z+1,r24
/* epilogue start */
	ret
	.size	_Z10init_timerv, .-_Z10init_timerv
	.section	.text._ZN5TimerIjE5delayEj,"axG",@progbits,_ZN5TimerIjE5delayEj,comdat
	.weak	_ZN5TimerIjE5delayEj
	.type	_ZN5TimerIjE5delayEj, @function
_ZN5TimerIjE5delayEj:
/* prologue: function */
/* frame size = 0 */
/* stack size = 0 */
.L__stack_usage = 0
	sts 2826,__zero_reg__
	sts 2826+1,__zero_reg__
	ldi r18,lo8(1)
	sts 2822,r18
	ldi r20,lo8(56)
	ldi r21,lo8(1)
	mul r24,r20
	movw r18,r0
	mul r24,r21
	add r19,r0
	mul r25,r20
	add r19,r0
	clr r1
	sts 2828,r18
	sts 2828+1,r19
	ldi r24,lo8(3)
	sts 2816,r24
.L3:
	lds r24,2822
	sbrs r24,0
	rjmp .L3
	sts 2816,__zero_reg__
/* epilogue start */
	ret
	.size	_ZN5TimerIjE5delayEj, .-_ZN5TimerIjE5delayEj
	.text
.global	_Z10send_pulsev
	.type	_Z10send_pulsev, @function
_Z10send_pulsev:
	push r17
	push r28
	push r29
/* prologue: function */
/* frame size = 0 */
/* stack size = 3 */
.L__stack_usage = 3
	ldi r28,lo8(96)
	ldi r29,lo8(4)
	ldi r17,lo8(2)
	std Y+5,r17
	ldi r24,lo8(10)
	ldi r25,0
	call _ZN5TimerIjE5delayEj
	std Y+6,r17
/* epilogue start */
	pop r29
	pop r28
	pop r17
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
.L8:
	lds r24,1128
	sbrs r24,0
	rjmp .L8
	lds r18,2842
	lds r19,2842+1
.L9:
	lds r24,1128
	sbrc r24,0
	rjmp .L9
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
	push r28
/* prologue: function */
/* frame size = 0 */
/* stack size = 1 */
.L__stack_usage = 1
	movw r18,r24
	subi r24,100
	sbc r25,__zero_reg__
	cpi r24,100
	cpc r25,__zero_reg__
	brsh .L14
	sts 2845,__zero_reg__
	ldi r24,lo8(10)
	sts 2844,r24
	ldi r24,lo8(-12)
	ldi r25,lo8(1)
	call _ZN5TimerIjE5delayEj
	ldi r28,lo8(-128)
	sts 1125,r28
	ldi r24,lo8(-12)
	ldi r25,lo8(1)
.L19:
	call _ZN5TimerIjE5delayEj
	sts 1126,r28
/* epilogue start */
	pop r28
	ret
.L14:
	movw r24,r18
	subi r24,75
	sbc r25,__zero_reg__
	sbiw r24,25
	brsh .L16
	sts 2845,__zero_reg__
	ldi r24,lo8(25)
	sts 2844,r24
	ldi r24,lo8(44)
	ldi r25,lo8(1)
	call _ZN5TimerIjE5delayEj
	ldi r28,lo8(-128)
	sts 1125,r28
	ldi r24,lo8(44)
	ldi r25,lo8(1)
	rjmp .L19
.L16:
	movw r24,r18
	sbiw r24,25
	sbiw r24,25
	brsh .L17
	sts 2845,__zero_reg__
	ldi r24,lo8(50)
	sts 2844,r24
	ldi r24,lo8(100)
	ldi r25,0
	call _ZN5TimerIjE5delayEj
	ldi r28,lo8(-128)
	sts 1125,r28
	ldi r24,lo8(100)
	ldi r25,0
	rjmp .L19
.L17:
	subi r18,1
	sbc r19,__zero_reg__
	sts 2845,__zero_reg__
	cpi r18,24
	cpc r19,__zero_reg__
	brsh .L18
	ldi r24,lo8(75)
	sts 2844,r24
	ldi r24,lo8(50)
	ldi r25,0
	call _ZN5TimerIjE5delayEj
	ldi r28,lo8(-128)
	sts 1125,r28
	ldi r24,lo8(50)
	ldi r25,0
	rjmp .L19
.L18:
	ldi r24,lo8(100)
	sts 2844,r24
	ldi r24,lo8(25)
	ldi r25,0
	call _ZN5TimerIjE5delayEj
	ldi r28,lo8(-128)
	sts 1125,r28
	ldi r24,lo8(25)
	ldi r25,0
	rjmp .L19
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
.L21:
	call _Z13measure_pulsev
	movw r22,r28
	call __udivmodhi4
	movw r24,r22
	call _Z13update_summerj
	rjmp .L21
	.size	main, .-main
	.ident	"GCC: (GNU) 12.2.0"
