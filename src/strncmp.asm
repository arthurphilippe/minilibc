	global	strncmp:function
	section	.text
strncmp:
	; parameters (rdi: s1, rsi: s2, rdx: size)
	; local variables
	xor	rax, rax		; idx
	inc	rdx
	jmp	.LCOND

.LBODY:
	mov	cl, BYTE [rsi+rax]
	mov	bl, BYTE [rdi+rax]
	cmp	cl, bl
	jne	.DIFF
	inc	rax

.LCOND:
	cmp	rdx, rax
	jne	.LBODY
	jmp	.SUCCESS

.DIFF:
	sub	bl, cl
	movsx	eax, bl
	jmp	.END

.SUCCESS:
	mov	eax, 0

.END:
	ret
