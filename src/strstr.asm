	global	strstr:function
	section	.text
strstr:
	; parameters (rdi: haystack, rsi: needle)
	; local variables
	xor	rax, rax		; idx
	jmp	.LBODY

.LBODY:
	mov	r8b, BYTE [rsi+rax] ; char from needle at pos rax
	mov	r9b, BYTE [rdi+rax] ; char from haystack at pos rax

	cmp	r8b, 0
	je	.SUCCESS

	cmp	r8b, r9b
	jne	.DIFF

	inc	rax
	jmp	.LBODY

.DIFF:
	inc	rdi
	cmp	byte [rdi], 0x0
	je	.FAILURE
	xor	rax, rax
	jmp	.LBODY

.FAILURE:
	mov	rax, 0x0
	jmp	.END

.SUCCESS:
	mov	rax, rdi

.END:
	ret
