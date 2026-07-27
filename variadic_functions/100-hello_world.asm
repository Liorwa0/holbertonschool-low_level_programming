section .data
	msg db "Hello, World", 10

section .text
	global main

main:
	mov rax, 1          ; system call number for sys_write
	mov rdi, 1          ; file descriptor 1 is stdout
	mov rsi, msg        ; address of string to output
	mov rdx, 13         ; length of string (12 chars + 1 newline)
	syscall             ; invoke system call

	mov rax, 60         ; system call number for sys_exit
	mov rdi, 0          ; exit code 0
	syscall             ; invoke system call
