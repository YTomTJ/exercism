default rel

%include "debug.mac"

; Everything that comes after a semicolon (;) is a comment.

section .text

; You should implement functions in the .text section.
; A skeleton is provided for the first function.

; the global directive makes a function visible to the test files.
global front_door_response
front_door_response:
    ; This function takes the address in memory for a line of the poem as an argument.
    ; It returns the first letter of that line, as a ASCII-encoded character.
    mov al, byte [rdi]
    ret

to_lower:
    cmp dl, 'A'
    jl .end
    cmp dl, 'Z'
    jg .end
    add dl, 32
.end:
    mov al, dl
    ret

to_upper:
    cmp dl, 'a'
    jl .end
    cmp dl, 'z'
    jg .end
    sub dl, 32
.end:
    mov al, dl
    ret

global front_door_password
front_door_password:
    ; This function takes as argument the address in memory for a string containing the combined letters you found in task 1.
    ; It must modify this string in-place, making it correctly capitalized.
    ; The function has no return value.
    mov rbx, 0
    mov rsi, rdi
    cld
.loop:
    lodsb
    cmp al, 0
    je .end
    mov dl, al
    cmp rbx, 0    ; check capial
    je .upper
.lower:
    call to_lower
    mov rdi, rsi
    sub rdi, 1
    stosb
    jmp .loop
.upper:
    inc rbx
    call to_upper
    mov rdi, rsi
    sub rdi, 1
    stosb
    jmp .loop
.end:
    ret

is_letter:
    cmp dl, 'A'
    jl .false
    cmp dl, 'z'
    jg .false
    cmp dl, 'Z'
    jle .true
    cmp dl, 'a'
    jge .true   
.false:
    mov rax, 0
    ret
.true:
    mov rax, 1
    ret
    
global back_door_response
back_door_response:
    ; This function takes as argument the address in memory for a line of the poem.
    ; It returns the last letter of that line that is not a whitespace character, as a ASCII-encoded character.
    mov rsi, rdi
    mov rbx, 0    ; the last letter
    cld
.loop:
    lodsb
    cmp al, 0
    je .end
    mov dl, al
    call is_letter
    cmp rax, 1
    jne .loop
    mov rbx, rdx
    jmp .loop
.end:
    mov rax, rbx
    ret

section .rodata
    please_msg db ", please.", 0

section .text

global back_door_password
back_door_password:
    ; This function takes as arguments, in this order:
    ; 1. The address in memory for a buffer where the resulting string will be stored.
    ; 2. The address in memory for a string containing the combined letters you found in task 3.
    ; It should store the polite version of the capitalized password in the buffer.
    ; A polite version is correctly capitalized and has ", please." added at the end.
    ; The function has no return value.
    cld
    mov r8, 0    ; the count
.loop:
    mov al, byte [rsi]
    cmp al, 0
    je .step2
    movsb
    inc r8
    jmp .loop
.step2:
    mov rbx, rdi
    sub rbx, r8    ; the first char
    mov dl, byte [rbx]
    call to_upper
    mov byte [rbx], al
    mov rdi, rbx
    add rdi, r8
    lea rsi, [please_msg]
.copy_loop:
    mov al, byte [rsi]
    cmp al, 0
    je .copy_end
    movsb
    jmp .copy_loop
.copy_end:
    mov [rdi], 0
    ret

%ifidn __OUTPUT_FORMAT__,elf64
section .note.GNU-stack noalloc noexec nowrite progbits
%endif
