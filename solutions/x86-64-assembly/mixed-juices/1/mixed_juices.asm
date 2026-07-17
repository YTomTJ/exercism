default rel

%include "debug.mac"

; Everything that comes after a semicolon (;) is a comment

section .rodata
    wait_time dd 1, 3, 3, 4, 5, 4, 7, 10


section .text

; You should implement functions in the .text section
; A skeleton is provided for the first function

; the global directive makes a function visible to the test files
global time_to_make_juice
time_to_make_juice:
    ; This function has one argument, the ID for a juice as a 32-bit number
    ; It returns the time to prepare this juice, as a 32-bit number
    sub edi, 1
    lea rax, [wait_time]
    mov eax, dword [rax + rdi * 4 + 0]
    ret

global time_to_prepare
time_to_prepare:
    ; This function has two arguments:
    ; - An array with the IDs for ordered juices, each ID a 32-bit number
    ; - The number of ordered juices, also a 32-bit number.
    ; It returns the total time to prepare all ordered juices, as a 32-bit number
    mov r8, 0 ; index
    mov r9, 0 ; sum
    mov r10, rdi ; array
    mov r11, rsi ; count
.loop:
    cmp r8, r11
    je .end
    mov rdi, [r10 + r8 * 4 + 0]
    call time_to_make_juice
    add r9, rax
    add r8, 1
    jmp .loop
.end:
    mov rax, r9
    ret

global limes_to_cut
limes_to_cut:
    ; This function takes three arguments:
    ; - The number of wedges needed, as a 32-bit number.
    ; - An array with the current supply of limes, each represented by a 8-bit number.
    ; - The number of limes in the supply, as a 32-bit number.
    ; It returns the number of limes that need to be cut, as a 32-bit number
    mov r8, 0 ; index
    mov r9, 0 ; total
.loop:
    cmp r8, rdx
    jge .end
    mov bl, byte [rsi + r8 * 1 + 0]
    cmp bl, 'S'
    jne .cmp_m
    add r9, 6
    jmp .cmp_end
.cmp_m:
    cmp bl, 'M'
    jne .cmp_l
    add r9, 8
    jmp .cmp_end
.cmp_l:
    ;cmp bl, 'L'
    add r9, 10
.cmp_end:
    add r8, 1
    cmp r9, rdi
    jge .end
    jmp .loop
.end:
    mov rax, r8
    ret

global remaining_orders
remaining_orders:
    ; This function takes two arguments:
    ; - The time left in the shift, as a 32-bit number.
    ; - An array  with the IDs for ordered juices still not prepared, each ID a 32-bit number.
    ; It returns the number of juices made before the shift ends, as a 32-bit number.
    ; You may consider that:
    ; - The array is never empty.
    ; - The time left in the shift at the beginning is always greater than 0.
    ; - There are more orders in the array than that which can be prepared before the shift ends.
    mov rax, 0 ; index
    mov rbx, 0 ; total
    lea rcx, [wait_time]
.loop:
    mov edx, dword [rsi + rax * 4 + 0]
    sub rdx, 1
    mov r8d, dword [rcx + rdx * 4 + 0]
    add rbx, r8
    add eax, 1
    cmp rbx, rdi
    jge .end
    jmp .loop
.end:
    ret

%ifidn __OUTPUT_FORMAT__,elf64
section .note.GNU-stack noalloc noexec nowrite progbits
%endif
