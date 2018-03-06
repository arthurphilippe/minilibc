	global	my_memcpy:function
	global	memcpy:function
	section	.text
my_memcpy:
memcpy:
	; parameters (rdi: dest, rsi: source, rdx: size)
	; local variables
	xor	rax, rax		; idx
	jmp	.LCOND

.LBODY:
	mov	cl, BYTE [rsi+rax]
	mov	BYTE [rdi+rax], cl
	inc	rax

.LCOND:
	cmp	rdx, rax
	ja	.LBODY

.END:
	mov	rax, rdi
	ret
