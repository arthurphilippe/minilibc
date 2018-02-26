		global	_start

		section	.text
_start:		mov	eax, 4		; linux syscall write
		mov	ebx, 1		; fd = 1
		mov	ecx, message	; buf = message
		mov	edx, len	; size = len
		int	0x80		; --> call
		mov	eax, 0x01	; linux syscall exit
		mov	ebx, 0		; exit status 0
		int	0x80		; --> call

		section	.data
message		db	"Hello, World", 10
len		equ	$-message
