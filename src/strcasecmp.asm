	global	my_strcasecmp:function
	global	strcasecmp:function
	section	.text
my_strcasecmp:
strcasecmp:
	; parameters (rdi: s1, rsi: s2, rdx: size)
	; local variables
	xor	rax, rax		; idx
	jmp	.LBODY

.LBODY:
	mov	cl, BYTE [rsi+rax]
	mov	bl, BYTE [rdi+rax]

	cmp	cl, 65
	jl	.SKIP_LOWERA
	cmp	cl, 90
	jg	.SKIP_LOWERA

	sub	cl, 65
	add	cl, 97

.SKIP_LOWERA:			; if cl is lower than A and greater than Z

	cmp	bl, 65
	jl	.SKIP_LOWERB
	cmp	bl, 90
	jg	.SKIP_LOWERB

	sub	bl, 65
	add	bl, 97

.SKIP_LOWERB:

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
