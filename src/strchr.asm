	global	strchr:function
	section	.text
strchr:
	push	rbp
	mov	rbp, rsp

	; arguments
	mov	QWORD [rbp-24], rdi
	mov	DWORD [rbp-28], esi

	; local vars
	mov	DWORD [rbp-4], 0	; prepare loop counter

	jmp	.LOOP

.INC:
	add	DWORD [rbp-4], 1
.LOOP:
	movsx	rdx, DWORD [rbp-4]	; recover loop counter as QWORD
	mov	rax, QWORD [rbp-24]	; recover str
	movzx	eax, BYTE [rax+rdx]	; str[i]
	cmp	DWORD [rbp-28], eax
	je	.SUCCESS
	cmp	al, 0
	jne	.INC

.FAIL:
	mov	rax, 0			; on failure returns null
	jmp	.END

.SUCCESS:
	movsx	rdx, DWORD [rbp-4]	; recover loop counter as QWORD
	mov	rax, QWORD [rbp-24]	; recover str
	add	rax, rdx

.END:
	pop	rbp			; restore base
	ret
