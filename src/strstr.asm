	global	my_strstr:function
	global	strstr:function
	section	.text
my_strstr:
strstr:
	; parameters (rdi: haystack, rsi: needle)
	; local variables
	xor	rax, rax		; idx
	jmp	.LBODY

.LBODY:
	mov	r8b, BYTE [rsi+rax]
	mov	r9b, BYTE [rdi+rax]

	cmp	r8b, 0
	je	.SUCCESS

	cmp	r8b, r9b
	ja	.DIFF

	inc	rax
	jmp	.LBODY

.DIFF:
	inc	rdi
	xor	rax, rax
	cmp	byte [rdi], 0x0
	je	.FAILURE
	jmp	.LBODY

.FAILURE:
	mov	rax, 0x0
	jmp	.END

.SUCCESS:
	mov	rax, rdi

.END:
	ret
