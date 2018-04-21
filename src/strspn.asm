	global	strspn:function
	section	.text
strspn:
	; parameters (rdi: str, rsi: accept)
	; local variables
	xor	rax, rax
	xor	r10, r10
	jmp	.LCOND

.LBODY:
	; if str[rax] == accept[r10] --> continue
	cmp	r9b, r8b
	je	.NEXTSTR

	; else --> r10++
	inc	r10
	mov	r8b, BYTE [rsi+r10] ; char from accept at pos rax

	; if accept[r10] != 0 --> continue
	cmp	r8b, 0x0
	jne	.LCOND
	; else --> its over
	jmp	.END

.NEXTSTR:
	inc	rax
	xor	r10, r10
	jmp	.LCOND

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
