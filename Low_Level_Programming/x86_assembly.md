[Home](../README.md#low-level-programming)

# x86 assembly
- Create your object file: `nasm -f elf64 file.asm -o files.o`
- Link your object files:  `ld file.o -o file`
- ;s are comments.

## Registers

| Sub-registers | Description                             |
|---------------|-----------------------------------------|
| al            | Lowest 8 bits                           |
| ah            | Highest 8 bits                          |
| ax            | Lowest 16 bits                          |
| eax           | Lowest 32 bits. Resets the top 32 bits. |
| rax           | 64 bits                                 |

| Register name | Description         |
|---------------|---------------------|
| rax           | Primary accumulator |
| rbx           | Base register       |
| rcx           | Count register      |
| rdx           | Data register       |
| r8-r15        | General purpose     |
| rbp           | Base pointer reg    |
| rsp           | Stack pointer reg   |

## Commands
Commands follow this syntax: cmd des, src
- The source(src) goes into the destination(des).
- The sources and destinations can either be a register, a memory address, or an immediate number/string.
	- All immediate values are limited to 32 bits.
	- If you have a negative immediate value, the sign is extended to the end of the 64 bits.

### Moving and conditional codes

| Commands        | Description                                                                 |
|-----------------|-----------------------------------------------------------------------------|
| mov des, src    | Copies the value form source to destination. Dereferences pointers.         |
| lea des, src    | Copies the value form source to destination. Doesn't dereferences pointers. |
| cmovCC des, src | Conditional move. cc is the conditional code.                               |

| Conditional Code(CC) | Description            | Flags              | Description                       |
|----------------------|------------------------|--------------------|-----------------------------------|
| e                    | Equals                 | ZF = 1             |                                   |
| ne                   | Not equal              | ZF = 0             |                                   |
| g                    | Greater than           | SF = OF and ZF = 0 |                                   |
| ge                   | Greater than or equals | SF = OF            |                                   |
| l                    | Less than              | SF != OF           |                                   |
| le                   | Less than or equals    | ZF = 1 or SF != OF |                                   |
| b                    | Below                  | CF = 1             | Unsigned less than                |
| nb                   | Not below              | CF = 0             | Unsigned greater than or equal to |
| a                    | Above                  | CF = 0 and ZF = 0  | Unsigned greater than             |
| na                   | Not above              | CF = 1 or ZF = 1   | Unsigned less than or equal to    |
| s                    | Sign                   | SF = 1             |                                   |
| ns                   | Not sign               | SF = 0             |                                   |
| p                    | Parity                 | PF = 1             |                                   |
| np                   | Not parity             | PF = 0             |                                   |

### Flags and Comparisons

These commands are used to set the flags and don't store the result.

| Commands      | Description  |
|---------------|--------------|
| cmp des, src  | Same as sub. |
| test des, src | Same as and. |

| Flags | Names         | Description                                                 | Example              |
|-------|---------------|-------------------------------------------------------------|----------------------|
| CF    | Carry flag    | Unsigned overflow                                           | 1111 + 0001 = 1 0000 |
| ZF    | Zero flag     | If the result is 0                                          |                      |
| SF    | Signed flag   | If the result is signed                                     |                      |
| OF    | Overflow flag | Signed overflow                                             | 0111 + 0001 = 1000   |
| PF    | Parity flag   | Count the number of 1 bits in the last 8 bits of the result |                      |

### Arithmetic

| Commands                  | Description                                                                |
|---------------------------|----------------------------------------------------------------------------|
| add des, src              |                                                                            |
| sub des, src              |                                                                            |
| inc des                   | Increment. Doesn't effect carry flag.                                      |
| dec des                   | Decrement. Doesn't effect carry flag.                                      |
| div des                   | Unsigned division. Answer in RAX and remainder in RDX.                     |
| idiv des                  | Signed division. Answer in RAX and remainder in RDX.                       |
| mul des or mul des, src   | Signed multiplication. Lower 128 bits(64 bits) in RAX and higher in RDX.   |
| imul des or imul des, src | Unsigned multiplication. Lower 128 bits(64 bits) in RAX and higher in RDX. |
| shl des, src              | Shift left. Multiplying by powers of 2.                                    |
| shr des, src              | Unsigned shift right. Dividing by powers of 2.                             |
| sar des, src              | Signed shift right. Dividing by powers of 2. If odd then round up.         |
| rol des, src              | Rotate left.                                                               |
| ror des, src              | Rotate right.                                                              |
| rcl des, src              | Rotate left through the carry flag.                                        |
| rcr des, src              | Rotate right through the carry flag.                                       |

- The src for shift commands can only be al or imm8.

### Logic gate

| Commands     | Description                                                 |
|--------------|-------------------------------------------------------------|
| and des, src | anding a reg with itself updates the flags with no changes. |
| or des, src  |                                                             |
| not des      | Flips bits.                                                 |
| neg des      | Negates signed numbers(2s compliment).                       |
| xor des, src | xoring a reg with itself makes it 0.                         |

### Jump

| Commands   | Description                                                                                                 |
|------------|-------------------------------------------------------------------------------------------------------------|
| call label | Transfers control to a subroutine at the label. The return address is pushed on the stack.                  |
| ret        | Returns from a subroutine. Pops the stack and uses the return address.                                      |
| syscall    | Makes a syscall to the operating system. The specific service is determined by values in certain registers. |
| jmp label  | Jumps to a label.                                                                                           |
| jCC label  | Conditional jump based on the conditional code.                                                             |

### Stack

| Commands | Description                                              |
|----------|----------------------------------------------------------|
| pop des  |                                                          |
| push des |                                                          |
| pushfq   | Push the contents of the rflags register onto the stack. |
| popfq    | Pop the stack onto the rflags register.                  |

```
Low
   +-----+ ^
	 +-----+ |
	 +-----+ |
	 +-----+ |
	 +-----+ |
	 +-----+ <- rsp
High
```

### Floats

## Sections and Start

| Sections | Description                                                                             |
|----------|-----------------------------------------------------------------------------------------|
| .data    | Used to declare global variables with values. Initialized values are in the executable. |
| .bss     | Used to declare global variable with 0s. It doesn't store 0 in the executable.          |
| .text    | Contains the executable instruction of the program.                                     |

- .bss is used to save 0s from being in the executable.

```assembly
section .text
	global _start

_start:
	; Your code goes here
	; Syscall exit
	mov rax, 60
	xor rdi, rdi ; Exit code 0
	syscall
```

## Variables
Variables take the form of: varName varSize immValue/?
- The s in front means it's signed.
- Immediate floats need to have decimal points. Ex: 10.0

| varSize         | Description            |
|-----------------|------------------------|
| byte/db/sbyte   | 8 bits                 |
| word/dw/sword   | 16 bits                |
| dword/dd/sdword | 32 bits                |
| qword/dq/sqword | 64 bits                |
| real4           | 32 floating point bits |
| real8           | 64 floating point bits |

### Arrays
- You can create arrays with a repeated patter using `times`.
	- Ex: `arrName times 5 db 0` creates an array of 5 bytes all initialized to 0.
- You can create arrays by listing out each element.
	- Ex: `arrName db 1, 2, 3, 4`
- You can use quotes(`"`s) to create arrays.
	- Ex: `str db "Hello, World!", 0xA`
- You can get teh size of an array using `equ`
	- Ex: `arrSize equ $ - arrName`

## Pointers

|                       | Description                                                             |
|-----------------------|-------------------------------------------------------------------------|
| `var`                 | Gets the value of var                                                   |
| `[ptr]`               | Dereferences the pointer                                                |
| `[reg/mem +/- # * #]` | The `* #` is the bytes of each array element. The `+/- #` is the index. |

- If you want to get the address of var, then use the lea command.

## Hello World

```assembly
section .data
	msg db "Hello, world!", 0xA   ; Message with newline
	len equ $ - msg               ; Calculate length of the message

section .text
	global _start                 ; Entry point for the program

_start:
	; Syscall write
	mov rax, 1                    ; System call number for write
	mov rdi, 1                    ; File descriptor 1 (stdout)
	mov rsi, msg                  ; Address of the message
	mov rdx, len                  ; Length of the message
	syscall                       ; Invoke the system call

	; Syscall exit
	mov rax, 60                   ; System call number for exit
	xor rdi, rdi                  ; Exit code 0
	syscall                       ; Invoke the system call
```