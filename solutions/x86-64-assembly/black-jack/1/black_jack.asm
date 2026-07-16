; Everything that comes after a semicolon (;) is a comment

C2 equ 2
C3 equ 3
C4 equ 4
C5 equ 5
C6 equ 6
C7 equ 7
C8 equ 8
C9 equ 9
C10 equ 10
CJ equ 11
CQ equ 12
CK equ 13
CA equ 14

TRUE equ 1
FALSE equ 0

section .text

; You should implement functions in the .text section

; the global directive makes a function visible to the test files
global value_of_card
value_of_card:
    ; This function takes as parameter a number representing a card
    ; The function should return the numerical value of the passed-in card
    ; card == 14
    cmp rdi, CA
    je .card_ca
    ; card == 11 12 13
    cmp rdi, CJ
    jge .card_face
    mov rax, rdi
    ret
.card_ca:
    mov rax, 1
    ret
.card_face:
    mov rax, 10
    ret

global higher_card
higher_card:
    ; This function takes as parameters two numbers each representing a card
    ; The function should return which card has the higher value
    ; If both have the same value, both should be returned
    ; If one is higher, the second one should be 0
    mov r10, rdi
    mov r11, rsi
    call value_of_card
    mov rsi, rax
    mov rdi, r11
    call value_of_card
    cmp rsi, rax
    jg .is_higher
    jl .is_lower
    mov rax, r10
    mov rdx, r11
    ret
.is_higher:
    mov rax, r10
    mov rdx, 0
    ret
.is_lower:
    mov rax, r11
    mov rdx, 0
    ret

global value_of_ace
value_of_ace:
    ; This function takes as parameters two numbers each representing a card
    ; The function should return the value of an upcoming ace
    cmp rdi, CA
    je .has_ace
    cmp rsi, CA
    je .has_ace
    call value_of_card
    mov r10, rax
    mov rdi, rsi
    call value_of_card
    add rax, r10
    add rax, 11
    cmp rax, 21
    jg .has_ace
    mov rax, 11
    ret
.has_ace:
    mov rax, 1
    ret

global is_blackjack
is_blackjack:
    ; This function takes as parameters two numbers each representing a card
    ; The function should return TRUE if the two cards form a blackjack, and FALSE otherwise
    cmp rdi, CA
    je .ca_at_one
    cmp rsi, CA
    je .ca_at_two
    jne .no_ace_or_failed
.ca_at_one:
    cmp rsi, CA
    je .no_ace_or_failed
    mov rdi, rsi
    call value_of_card
    cmp rax, 10
    je .black_jack
    jne .no_ace_or_failed
.ca_at_two:
    call value_of_card
    cmp rax, 10
    je .black_jack
    jne .no_ace_or_failed
.black_jack:
    mov rax, TRUE
    ret
.no_ace_or_failed:
    mov rax, FALSE
    ret

global can_split_pairs
can_split_pairs:
    ; This function takes as parameters two numbers each representing a card
    ; The function should return TRUE if the two cards can be split into two pairs, and FALSE otherwise
    cmp rdi, rsi
    je .is_same
    call value_of_card
    mov r10, rax
    mov rdi, rsi
    call value_of_card
    add rax, r10
    cmp rax, 20
    je .is_same
.not_same:
    mov rax, FALSE
    ret
.is_same:
    mov rax, TRUE
    ret

global can_double_down
can_double_down:
    ; This function takes as parameters two numbers each representing a card
    ; The function should return TRUE if the two cards form a hand that can be doubled down, and FALSE otherwise
    call value_of_card
    mov r10, rax
    mov rdi, rsi
    call value_of_card
    add rax, r10
    cmp rax, 9
    jl .no_double
    cmp rax, 11
    jg .no_double
    mov rax, TRUE
    ret
.no_double:
    mov rax, FALSE
    ret

%ifidn __OUTPUT_FORMAT__,elf64
section .note.GNU-stack noalloc noexec nowrite progbits
%endif
