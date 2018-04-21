	global	strpbrk:function
	section	.text

strpbrk:
	; parameters (rdi: string, rsi: accept)
	; local variables
	xor	rax, rax		; idx
	mov	r8b, BYTE [rsi] ; char from accept at pos rax
	mov	r9b, BYTE [rdi] ; char from string at pos rax
	cmp	r9b, 0x0
	je	.FAILURE

.LBODY:
	mov	r9b, BYTE [rdi] ; char from string at pos rax

	; if r8b == r9b --> success
	cmp	r8b, r9b
	je	.SUCCESS

	; advance onto the next accept char
	inc	rax
	mov	r8b, BYTE [rsi+rax]

	; if new r8b is not nil --> continue
	cmp	r8b, 0x0
	jne	.LBODY

	; else advance onto the next string char
	inc	rdi

	; if new *rdi is nil --> it's a failure
	cmp	byte [rdi], 0x0
	je	.FAILURE

	; else --> resset rax and r8b
	xor	rax, rax
	mov	r8b, BYTE [rsi+rax]
	jmp	.LBODY

.FAILURE:
	mov	rax, 0x0
	jmp	.END

.SUCCESS:
	mov	rax, rdi

.END:
	ret
