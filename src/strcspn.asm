	global	strcspn:function
	section	.text
strcspn:
	; parameters (rdi: str, rsi: accept)
	; local variables
	xor	rax, rax
	xor	r10, r10
	jmp	.LCOND

.LBODY:
	cmp	r9b, r8b
	jne	.ADVANCE_REJECT
	je	.END

.ADVANCE_REJECT:
	inc	r10
	mov	r8b, BYTE [rsi+r10] ; char from accept at pos rax

	; if it is not the end of reject --> continue
	cmp	r8b, 0x0
	jne	.LBODY

	; else --> reset reject and increment rax
	xor	r10, r10
	inc	rax

.LCOND:
	mov	r9b, BYTE [rdi+rax] ; char from string at pos rax
	; if str[rax] == 0 --> its over
	cmp	r9b, 0x0
	je	.END
	; else --> go back to the loop
	mov	r8b, BYTE [rsi+r10] ; char from accept at pos rax
	jmp	.LBODY

.END:
	ret
