		global	my_strlen:function
		section	.text
my_strlen:
	push	rbp
	mov	rbp, rsp
	mov	QWORD [rbp-24], rdi	; copy the argument
	mov	DWORD [rbp-4], 0	; prepare loop counter
	jmp	.LOOP

.INC:
	add	DWORD [rbp-4], 1
.LOOP:
	movsx	rdx, DWORD [rbp-4]	; recover loop counter as QWORD
	mov	rax, QWORD [rbp-24]	; recover str
	movzx	eax, BYTE [rax+rdx]	; str[i]
	cmp	al, 0
	jne	.INC
	mov	eax, DWORD [rbp-4]	; return (i)
	pop	rbp
	ret
