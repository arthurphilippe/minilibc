	global	my_strncmp:function
	; global	strncmp:function
	section	.text
my_strncmp:
; strncmp:
	; parameters (rdi: dest, rsi: source, rdx: size)
	; local variables
	xor	rax, rax		; idx
	jmp	.LCOND

.LBODY:
	mov	cl, BYTE [rsi+rax]
	mov	bl, BYTE [rdi+rax]
	cmp	cl, bl
	ja	.DIFF
	inc	rax

.LCOND:
	cmp	rdx, rax
	ja	.LBODY
	jmp	.SUCCESS

.DIFF:
	sub	bl, cl
	movsx	eax, bl
	jmp	.END

.SUCCESS:
	mov	eax, 0

.END:
	ret
