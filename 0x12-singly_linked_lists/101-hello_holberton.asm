	SECTION .data
message: db "Hello, Holberton", 0
format: db "%s", 0AH, 0

	SECTION .text
	extern printf
	global main
main:
	mov esi, message
	mov edi, format
	mov eax, 0
	call printf

	mov eax, 0
	ret
