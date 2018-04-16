	global	rindex:function
	section	.text
rindex:
	push	rbp
	mov	rbp, rsp

	; arguments (rdi: str, esi: char)
	; local vars
	xor	rdx, rdx
	xor	rbx, rbx
	jmp	.LOOP

.FOUND:
	mov	rbx, rdx
	cmp	al, 0
	je	.SUCCESS

.INC:
	inc	rdx
.LOOP:
	movzx	eax, BYTE [rdi+rdx]	; str[i]
	cmp	esi, eax
	je	.FOUND
	cmp	al, 0
	jne	.INC

	movzx	eax, BYTE [rdi+rbx]
	cmp	esi, eax
	je	.SUCCESS

.FAIL:
	mov	rax, 0			; on failure returns null
	jmp	.END

.SUCCESS:
	mov	rax, rdi		; recover str
	add	rax, rbx

.END:
	pop	rbp			; restore base
	ret
