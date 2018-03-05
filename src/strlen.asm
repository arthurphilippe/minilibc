	global	strlen:function
	section	.text
strlen:
	push	rbp
	mov	rbp, rsp

	; arguments
	mov	QWORD [rbp-24], rdi

	mov	rax, 0	; prepare loop counter
	jmp	.LOOP

.INC:
	add	rax, 1
.LOOP:
	mov	rdx, QWORD [rbp-24]	; recover str
	movzx	eax, BYTE [rdx+rax]	; str[i]
	cmp	al, 0
	jne	.INC

.END:
	pop	rbp			; restore base
	ret
