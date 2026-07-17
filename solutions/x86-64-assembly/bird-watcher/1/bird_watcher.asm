default rel

%include "debug.mac"

; Everything that comes after a semicolon (;) is a comment

section .data
    last_week db 0, 2, 5, 3, 7, 8, 4, 0
    current_week db 0, 0, 0, 0, 0, 0, 0, 0
    current_day db 0

section .text

; You should implement functions in the .text section
; A skeleton is provided for the first function

; the global directive makes a function visible to the test files
global last_week_counts
last_week_counts:
    ; This function takes no parameter
    ; It returns a copy of last week's counts as a 8-byte number
    ; At the start of the program, last week's counts are 0, 2, 5, 3, 7, 8 and 4
    ; The last byte of the return value is always zero
    mov rax, qword [last_week]
    ret

global current_week_counts
current_week_counts:
    ; This function takes no parameter
    ; It returns two values:
    ; - A copy of current week's counts as a 8-byte number.
    ; - The number of days already filled in the current week, as a 8-byte number.
    ; All days after the most recent one should have its corresponding byte zeroed-out in the output
    ; At the start of the program, there is no count for the current week
    lea rbx, [current_week]
    mov rax, qword [rbx]
    mov rdx, 0
    ; count days
    mov rcx, 0 ; offset
.count_loop:
    cmp [rbx + rcx * 1 + 0], 0
    jng .next
    add rdx, 1
.next:
    add rcx, 1
    cmp rcx, 7
    jne .count_loop
    ; end of count_loop
    ret

global save_count
save_count:
    ; This function takes as parameter the most recent count, as a 1-byte number
    ; It must save this value in a new entry for the current week
    ; If there is already 7 entries in the current week before the function is called, then:
    ; - The current week becomes the last week.
    ; - A new entry is added with the passed value in a new current week.
    ; The function has no return value
    mov rax, [current_day]
    cmp rax, 7
    jne .process
    mov rax, 0
    ; copy to last week
    mov r10, qword [current_week]
    mov qword [last_week], r10
    mov qword [current_week], 0
.process:
    lea rbx, [rel current_week]
    mov byte [rbx + rax * 1 + 0], dil ; save today's count
    add rax, 1
    mov [current_day], rax
    ret

global today_count
today_count:
    ; This function has no parameter
    ; It returns the most recent entry for the current week, as a 1-byte number
    lea rbx, [rel current_week]
    mov rax, [current_day]
    cmp rax, 0
    je .is_fisrt
    sub rax, 1
    jmp .read_today
.is_fisrt:
    mov rax, 6
.read_today:
    mov al, byte [rbx + rax * 1 + 0]
    ret

global update_today_count
update_today_count:
    ; This function takes as parameter a 1-byte number
    ; It adds this number to the most recent entry for the current week
    ; This function has no return value
    lea rbx, [rel current_week]
    mov rax, [current_day]
    cmp rax, 0
    je .is_fisrt
    sub rax, 1
    jmp .update_today
.is_fisrt:
    mov rax, 6
.update_today:
    add byte [rbx + rax * 1 + 0], dil
    ret

global update_week_counts
update_week_counts:
    ; This function takes as parameter a 8-byte number
    ; Each byte in the input parameter, but the last, represents a day's count in the current week
    ; The last byte in the input parameter has no meaning and must be zeroed-out
    ; This function makes the following changes:
    ; - The current week becomes the last week.
    ; - The counts in the input parameter are fully inserted in the current week.
    mov rax, qword [current_week]
    mov qword [last_week], rax
    mov qword [current_week], rdi
    ret

%ifidn __OUTPUT_FORMAT__,elf64
section .note.GNU-stack noalloc noexec nowrite progbits
%endif
