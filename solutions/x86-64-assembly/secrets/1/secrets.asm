; Everything that comes after a semicolon (;) is a comment

section .text

; You should implement functions in the .text section
; A skeleton is provided for the first function

; the global directive makes a function visible to the test files
global extract_higher_bits
extract_higher_bits:
    ; This function has a 16-bit integer as argument.
    ; it returns the higher 8-bit value of the argument.
    mov rax, rdi
    shr rax, 8
    ret

global extract_lower_bits
extract_lower_bits:
    ; This function takes one 16-bit integer as argument and must return the lower 8-bit value of it.
    mov rax, rdi
    and rax, 0xFF
    ret

global extract_redundant_bits
extract_redundant_bits:
    ; This function takes one 16-bit integer as argument.
    ; It returns a 8-bit integer with all bits set in both the lower and the higher 8 bits of the argument.
    mov r10, rdi ; the mask
    shr r10, 8
    mov rax, rdi ; the message
    and rax, r10
    ret

global set_message_bits
set_message_bits:
    ; This function takes one 16-bit integer as argument.
    ; It returns a 8-bit integer with all bits set if they are set in the higher 8 bits of the argument, the others unchanged.
    mov r10, rdi ; the mask
    shr r10, 8
    mov rax, rdi ; the message
    or rax, r10
    ret

global rotate_private_key
rotate_private_key:
    ; This function takes one 16-bit integer as argument.
    ; It returns a 16-bit integer with bits of the private key rotated to the left a number of positions equal to the redundant bits.
    ; The private key is 0b1011_0011_0011_1100.
    ; A bit is redundant when it is set in both the lowest 8-bit portion of the argument and the highest 8-bit portion of the argument.
    call extract_redundant_bits
    popcnt rbx, rax
    mov cl, bl
    mov r10w, 0b1011_0011_0011_1100
    rol r10w, cl
    mov ax, r10w
    ret

global format_private_key
format_private_key:
    ; This function takes one 16-bit integer as argument.
    ; It returns a 8-bit integer with the private key fully formatted.
    ; To format a private key, you must:
    ; - Rotate it.
    ; - Isolate the lowest 8-bit portion of the rotated private key, which is the base value.
    ; - Isolate the highest 8-bit portion of the rotated private key, which is a mask to be applied to the base value.
    ; - Flip set bits in the base value that are also set in the mask.
    ; - Flip all bits in the result.
    call rotate_private_key
    mov r10, rax
    and r10, 0xFF ; base value
    mov r11, rax
    shr r11, 8    ; mask
    mov r12, r11
    not r12       ; inverse mask
    mov rax, r12
    ; v = (b & !mask) | (!b & mask)
    mov rax, r10
    and rax, r12
    not r10
    and r10, r11
    or rax, r10
    ; !v
    not rax
    ret

global decrypt_message
decrypt_message:
    ; This function takes one 16-bit integer as argument
    ; It returns a 16-bit integer, of which:
    ; - The higher 8 bits are the formatted private key, according to 'format_private_key'
    ; - The lower 8 bits are the message with all bits set, according to 'set_message_bits'
    mov r12, rdi
    call set_message_bits
    mov r8, rax
    and r8, 0xFF
    mov rdi, r12
    call format_private_key
    shl rax, 8
    or rax, r8
    ret

%ifidn __OUTPUT_FORMAT__,elf64
section .note.GNU-stack noalloc noexec nowrite progbits
%endif
