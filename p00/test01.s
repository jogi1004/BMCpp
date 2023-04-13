	.file	"test01.cc"
__SP_H__ = 0x3e
__SP_L__ = 0x3d
__SREG__ = 0x3f
__RAMPZ__ = 0x3b
__CCP__ = 0x34
__tmp_reg__ = 0
__zero_reg__ = 1
	.text
	.section	.text._ZSt7reverseIPcEvT_S1_,"axG",@progbits,_ZSt7reverseIPcEvT_S1_,comdat
	.weak	_ZSt7reverseIPcEvT_S1_
	.type	_ZSt7reverseIPcEvT_S1_, @function
_ZSt7reverseIPcEvT_S1_:
	push r28
	push r29
/* prologue: function */
/* frame size = 0 */
/* stack size = 2 */
.L__stack_usage = 2
	movw r30,r22
	movw r26,r24
.L2:
	cp r26,r30
	cpc r27,r31
	brlo .L3
/* epilogue start */
	pop r29
	pop r28
	ret
.L3:
	ld r24,X+
	ld r25,Z
	movw r28,r26
	sbiw r28,1
	st Y,r25
	st Z,r24
	sbiw r30,1
	rjmp .L2
	.size	_ZSt7reverseIPcEvT_S1_, .-_ZSt7reverseIPcEvT_S1_
	.section	.text.startup,"ax",@progbits
.global	main
	.type	main, @function
main:
/* prologue: function */
/* frame size = 0 */
/* stack size = 0 */
.L__stack_usage = 0
	lds r19,v1
	ldi r18,0
	ldi r20,lo8(10)
.L5:
	mov r30,r18
	ldi r31,0
	subi r18,lo8(-(1))
	subi r30,lo8(-(r1))
	sbci r31,hi8(-(r1))
	mov r24,r19
	mov r22,r20
	call __udivmodqi4
	subi r25,lo8(-(48))
	st Z,r25
	mov r25,r19
	mov r19,r24
	cpi r25,lo8(10)
	brsh .L5
	mov r24,r18
	subi r24,1
	sbc r25,r25
	movw r22,r24
	subi r22,lo8(-(r1))
	sbci r23,hi8(-(r1))
	ldi r24,lo8(r1)
	ldi r25,hi8(r1)
	call _ZSt7reverseIPcEvT_S1_
	lds r18,v2
	ldi r19,0
	ldi r20,lo8(10)
	sbrs r18,7
	rjmp .L9
	neg r18
	ldi r24,lo8(45)
	sts r2,r24
	ldi r19,0
	ldi r26,lo8(10)
.L7:
	mov r30,r19
	ldi r31,0
	subi r19,lo8(-(1))
	movw r20,r30
	subi r20,-1
	sbci r21,-1
	subi r30,lo8(-(r2+1))
	sbci r31,hi8(-(r2+1))
	mov r24,r18
	mov r22,r26
	call __udivmodqi4
	subi r25,lo8(-(48))
	st Z,r25
	mov r25,r18
	mov r18,r24
	cpi r25,lo8(10)
	brsh .L7
	movw r22,r20
	clr r23
	subi r22,lo8(-(r2))
	sbci r23,hi8(-(r2))
	ldi r24,lo8(r2+1)
	ldi r25,hi8(r2+1)
.L17:
	call _ZSt7reverseIPcEvT_S1_
	lds r19,v3
	ldi r18,0
	ldi r20,lo8(10)
.L10:
	mov r30,r18
	ldi r31,0
	subi r18,lo8(-(1))
	subi r30,lo8(-(r3))
	sbci r31,hi8(-(r3))
	mov r24,r19
	mov r22,r20
	call __udivmodqi4
	subi r25,lo8(-(48))
	st Z,r25
	mov r25,r19
	mov r19,r24
	cpi r25,lo8(10)
	brsh .L10
	mov r24,r18
	subi r24,1
	sbc r25,r25
	movw r22,r24
	subi r22,lo8(-(r3))
	sbci r23,hi8(-(r3))
	ldi r24,lo8(r3)
	ldi r25,hi8(r3)
	call _ZSt7reverseIPcEvT_S1_
	lds r19,v4
	ldi r18,0
	ldi r20,lo8(10)
.L11:
	mov r30,r18
	ldi r31,0
	subi r18,lo8(-(1))
	subi r30,lo8(-(r4))
	sbci r31,hi8(-(r4))
	mov r24,r19
	mov r22,r20
	call __udivmodqi4
	subi r25,lo8(-(48))
	st Z,r25
	mov r25,r19
	mov r19,r24
	cpi r25,lo8(10)
	brsh .L11
	mov r24,r18
	subi r24,1
	sbc r25,r25
	movw r22,r24
	subi r22,lo8(-(r4))
	sbci r23,hi8(-(r4))
	ldi r24,lo8(r4)
	ldi r25,hi8(r4)
	call _ZSt7reverseIPcEvT_S1_
	lds r30,index
	lds r31,index+1
	subi r30,lo8(-(_ZN5Sinus4dataE))
	sbci r31,hi8(-(_ZN5Sinus4dataE))
	ld r24,Z
	ldi r25,0
/* epilogue start */
	ret
.L9:
	mov r30,r19
	ldi r31,0
	subi r19,lo8(-(1))
	subi r30,lo8(-(r2))
	sbci r31,hi8(-(r2))
	mov r24,r18
	mov r22,r20
	call __udivmodqi4
	subi r25,lo8(-(48))
	st Z,r25
	mov r25,r18
	mov r18,r24
	cpi r25,lo8(10)
	brsh .L9
	mov r24,r19
	subi r24,1
	sbc r25,r25
	movw r22,r24
	subi r22,lo8(-(r2))
	sbci r23,hi8(-(r2))
	ldi r24,lo8(r2)
	ldi r25,hi8(r2)
	rjmp .L17
	.size	main, .-main
.global	v4
	.section .bss
	.type	v4, @object
	.size	v4, 1
v4:
	.zero	1
.global	v3
	.type	v3, @object
	.size	v3, 1
v3:
	.zero	1
.global	v2
	.type	v2, @object
	.size	v2, 1
v2:
	.zero	1
.global	v1
	.type	v1, @object
	.size	v1, 1
v1:
	.zero	1
.global	r4
	.type	r4, @object
	.size	r4, 6
r4:
	.zero	6
.global	r3
	.type	r3, @object
	.size	r3, 5
r3:
	.zero	5
.global	r2
	.type	r2, @object
	.size	r2, 4
r2:
	.zero	4
.global	r1
	.type	r1, @object
	.size	r1, 3
r1:
	.zero	3
.global	index
	.type	index, @object
	.size	index, 2
index:
	.zero	2
	.weak	_ZN5Sinus4dataE
	.section	.rodata._ZN5Sinus4dataE,"aG",@progbits,_ZN5Sinus4dataE,comdat
	.type	_ZN5Sinus4dataE, @gnu_unique_object
	.size	_ZN5Sinus4dataE, 10
_ZN5Sinus4dataE:
	.byte	127
	.byte	-54
	.byte	-8
	.byte	-8
	.byte	-54
	.byte	127
	.byte	52
	.byte	6
	.byte	6
	.byte	52
	.ident	"GCC: (GNU) 12.2.0"
.global __do_copy_data
.global __do_clear_bss
