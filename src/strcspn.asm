	global	strcspn:function
	section	.text
strcspn:
	; parameters (rdi: str, rsi: accept)
	; local variables
	xor	rax, rax		; idx
	jmp	.COND1

.LBODY:
	cmp	r8b, r9b
	je	.INC

.COND2:
	inc	rcx
	mov	r9b, BYTE [rsi+rcx]
	cmp	r9b, 0x0
	je	.END
	jmp	.LBODY

.INC:
	inc	rax

.COND1:
	xor	rcx, rcx		; idx accept
	mov	r9b, BYTE [rsi+rcx]
	mov	r8b, BYTE [rdi+rax]
	cmp	r8b, 0x0
	je	.END
	jmp	.LBODY

.END:
	ret
