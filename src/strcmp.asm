	global	my_strcmp:function
	global	strcmp:function
	section	.text
my_strcmp:
strcmp:
	; parameters (rdi: s1, rsi: s2, rdx: size)
	; local variables
	xor	rax, rax		; idx
	jmp	.LBODY

.LBODY:
	mov	cl, BYTE [rsi+rax]
	mov	bl, BYTE [rdi+rax]

	cmp	cl, bl
	jne	.DIFF

	cmp	cl, 0
	je	.SUCCESS

	inc	rax
	jmp	.LBODY

.DIFF:
	sub	bl, cl
	movsx	eax, bl
	jmp	.END

.SUCCESS:
	mov	eax, 0

.END:
	ret
