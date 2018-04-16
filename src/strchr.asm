	global	strchr:function
	section	.text
strchr:
	push	rbp
	mov	rbp, rsp

	; arguments (rdi: str, esi: char)
	mov	QWORD [rbp-24], rdi

	; local vars
	xor	rdx, rdx
	jmp	.LOOP

.INC:
	inc	rdx
.LOOP:
	movzx	eax, BYTE [rdi+rdx]	; str[i]
	cmp	esi, eax
	je	.SUCCESS
	cmp	al, 0
	jne	.INC

.FAIL:
	mov	rax, 0			; on failure returns null
	jmp	.END

.SUCCESS:
	mov	rax, QWORD [rbp-24]	; recover str
	add	rax, rdx

.END:
	pop	rbp			; restore base
	ret
