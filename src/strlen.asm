	global	my_strlen:function
	global	strlen:function
	section	.text
my_strlen:
strlen:
	mov	rax, 0			; prepare loop counter and ret value
	jmp	.LOOP

.INC:
	add	rax, 1
.LOOP:
	cmp	BYTE [rdi+rax], 0	; str[i] != 0
	jne	.INC

.END:
	ret
