	global	strlen:function
	section	.text
strlen:
	push	rbp
	mov	rbp, rsp

	; arguments
	mov	QWORD [rbp-24], rdi

	mov	rax, 0			; prepare loop counter and ret value
	jmp	.LOOP

.INC:
	add	rax, 1
.LOOP:
	cmp	BYTE [rbp-24+rax], 0	; str[i] != 0
	jne	.INC

.END:
	pop	rbp			; restore base
	ret
