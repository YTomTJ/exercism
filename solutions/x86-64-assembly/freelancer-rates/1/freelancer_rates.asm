default rel

; Everything that comes after a semicolon (;) is a comment.
section .rodata
    eight   dq 8
    hundred dq 100
    monthday dq 22

section .text

; You should implement functions in the .text section.
; A skeleton is provided for the first function.

; The global directive makes a function visible to the test files.
global daily_rate
daily_rate:
    ; This function takes an hourly_rate, as a 64-bit floating-point number.
    ; It returns the daily rate, also as a 64-bit floating-point number.
    ; A day has 8 billable hours.
    cvtsi2sd xmm1, [eight]
    mulsd xmm0, xmm1
    ret

global apply_discount
apply_discount:
    ; It takes as parameters a price and a discount in percent, both as 64-bit floating-point number.
    ; It returns the price with discount applied, as a 64-bit floating-point number.
    cvtsi2sd xmm2, [hundred]
    movsd xmm3, xmm0
    mulsd xmm3, xmm1
    divsd xmm3, xmm2
    subsd xmm0, xmm3
    ret

global monthly_rate
monthly_rate:
    ; It takes as parameters an hourly_rate and a discount in percent, both as a 64-bit floating-point number.
    ; It returns the discounted monthly rate, as a 64-bit integer, rounded up.
    ; A month has 22 billable days.
    cvtsi2sd xmm2, [monthday]
    mulsd xmm0, xmm2
    cvtsi2sd xmm2, [eight]
    mulsd xmm0, xmm2
    call apply_discount
    roundsd xmm0, xmm0, 2
    cvtsd2si rax, xmm0
    ret

global days_in_budget
days_in_budget:
    ; It takes as parameters:
    ; 1. A budget as a 64-bit unsigned integer.
    ; 2. An hourly_rate, as a 64-bit floating-point number.
    ; 3. A discount in percent, as a 64-bit floating-point number.
    ; It returns the number of complete days of work the budget covers, as a 32-bit unsigned integer, rounded down.
    cvtsi2sd xmm2, [hundred]
    subsd xmm2, xmm1
    cvtsi2sd xmm1, [hundred]
    divsd xmm2, xmm1
    cvtsi2sd xmm1, rdi
    divsd xmm1, xmm2
    divsd xmm1, xmm0
    cvtsi2sd xmm2, [eight]
    divsd xmm1, xmm2
    roundsd xmm1, xmm1, 1
    cvtsd2si rax, xmm1
    ret

%ifidn __OUTPUT_FORMAT__,elf64
section .note.GNU-stack noalloc noexec nowrite progbits
%endif
