# Masm(Microsoft assembly)

<!-- TOC -->

- [Comments](#comments)
- [Literals/Immediate](#literalsimmediate)
- [Symbols](#symbols)
- [Endianess](#endianess)
- [Registers](#registers)
	- [General Purpose Registers](#general-purpose-registers)
	- [Unaccessible registers](#unaccessible-registers)
	- [Flags](#flags)
- [data](#data)
	- [Binary coded decimalsBCD](#binary-coded-decimalsbcd)
	- [Arrays and Directives](#arrays-and-directives)
	- [Pointers](#pointers)
	- [Direct addressing - Using an index](#direct-addressing---using-an-index)
	- [Indirect addressing - Using a memory location](#indirect-addressing---using-a-memory-location)
- [code](#code)
	- [Modifying flags](#modifying-flags)
	- [Arithmetic](#arithmetic)
		- [Addition and Subtraction](#addition-and-subtraction)
		- [Multiplying](#multiplying)
		- [Dividing](#dividing)
		- [Bitwise](#bitwise)
		- [Shifting and Rotating](#shifting-and-rotating)
	- [Loops](#loops)
	- [Procedures and the Stack](#procedures-and-the-stack)
	- [Calling conventions](#calling-conventions)
	- [Jumps and Conditions](#jumps-and-conditions)
		- [Conditional directives](#conditional-directives)
	- [System calls](#system-calls)
- [Recursion](#recursion)
- [Special array commands](#special-array-commands)
- [Caching](#caching)

<!-- /TOC -->

## Comments
```asm
; Single line comments
comment !
	Multi line comments
	Can use any matching pair of symbols
!
```

## Literals/Immediate

| Examples            | Number System     |
|---------------------|-------------------|
| 11 or 11d           | Decimal           |
| 00001011b           | Binary            |
| 11h                 | Hex               |
| 'H' or "H"          | Character(1 byte) |
| 2. or 2.1 or 40.2E5 | Float             |

- Hex literals cannot start with an alphanumeric character. Ex: 0Fh
- Embedded quotes. Ex: 'Say "Hello"'
- Use `0dh, 0ah` for new lines in strings.

## Symbols
- Replaced at assembly time. Not at run time.

```asm
varName = 10
constName equ 10
constString equ <"String", 0>
```

- You can do simple math: ()s, -(negative sign), */, MOD, +-
- `$` gets the current address. Ex: arrLength equ ($ - arr) / 4

## Endianess
Example: 0x1429FD2E

Little endian(Intel) - Opposite to arrays. Useful for aligning.
| Address | Value |
|---------|-------|
| 0       | 2E    |
| 1       | FD    |
| 2       | 29    |
| 3       | 14    |

Big endian(Arm)      - Same as arrays. Not as useful for aligning.
| Address | Value |
|---------|-------|
| 0       | 14    |
| 1       | 29    |
| 2       | FD    |
| 3       | 2E    |

## Registers

### General Purpose Registers

 ____ ____ ____ ____
|        eax        | <- 4 bytes
          |    ax   | <- 2 bytes
					| ah | al | <- 1 byte not for esi, edi, ebp, or esp

| Names | Description                   |
|-------|-------------------------------|
| eax   | Usually used for accumulating |
| ebx   |                               |
| ecx   | Usually used for counting     |
| edx   |                               |
| esi   |                               |
| edi   |                               |
| ebp   | Base pointer                  |
| esp   | Stack pointer                 |

### Unaccessible registers

| Names  | Description         |
|--------|---------------------|
| eip    | Instruction pointer |
| eflags | Flags register      |
| ds     | Data segment        |
| ss     | Stack segment       |
| cs     | Code segment        |
| hs     | Heap segment        |


### Flags

| Name | Symbol              | Description                                                |
|------|---------------------|------------------------------------------------------------|
| OF   | Overflow flag       | Signed integer overflow                                    |
| CF   | Carry flag          | Unsigned integer overflow                                  |
| SF   | Sign flag           | Is the result negative                                     |
| ZF   | Zero flag           | Is the result 0                                            |
| PF   | Parity flag         | Even number of 1s in the least significant byte            |
| AC   | Auxiliary cary flag | Used for BCD. Is there a carry between the 3rd and 4th bit |

- Overflow flag is set by XORing the overflow bit of the sub/add and the most significant bit of the result.

## .data
- `varName dataType literal`

| Data Type | Bytes | Bits | Description          |
|-----------|-------|------|----------------------|
| byte      | 1     | 8    | Int                  |
| word      | 2     | 16   | Int                  |
| dword     | 4     | 32   | Int                  |
| qword     | 8     | 64   | Int                  |
| tbyte     | 10    | 80   | Binary coded decimal |
| real4     | 4     | 32   | Float                |
| real8     | 8     | 64   | Float                |
| real10    | 10    | 80   | Float                |

- Optional `s` in front for sign(sbyte), but asm doesn't have any concept of sign.
- Cannot reference another variable in data
- `?` for unutilized. Ex: `var1 byte ?`

### Binary coded decimals(BCD)
- Each decimal digit is represented by a 4 bit binary number. Ex: 15d -> 0001 0101b
- Most significant byte is used for the sign.
- Literals have to be written in hex or binary.

```asm
.data
	num1 tbyte 34120000000000000000h ; 1234 decimal
	num1 tbyte 34120000000000000080h ; -1234 decimal
```

### Arrays and Directives
- `arrName dataType ele1, ele2` or `arrName dataType size dup(defaultValues)`
	- These can be combined: Ex: `str byte 5 dup('_'), 0`

| Directive Name         | Description                                       |
|------------------------|---------------------------------------------------|
| type                   | Size of the elements                              |
| lengthof               | Number of elements                                |
| sizeof                 | Number of bytes. type * lengthof                  |
| align #                | Adds that many bytes in .data. Used for aligning. |
| varname label dataType | Takes up no storage. Like union in C              |

- `type` can also be used for variables.
- You can define arrays on multiple lines

```asm
.data
	arr byte 0, 1, 2, 3
	    byte 4, 5, 6, 7
```

### Pointers
- `type ptr dataName`
	- Used to change the type of a .data variable/array element. Not registers.

```asm
.data
	var1 dword 12345678h
.code
	mov byte ptr [var1 + 3], 21  ; var1 is 21345678h. Little endian so index 0 is LSB.
```

### Direct addressing - Using an index
- `arr[index * type arr]`
	- MASM automatically writes the code so this is done at run time.

```asm
.data
	arr1 word 0, 1, 2, 3, 4
.code
	mov ax, arr1[2 * type arr1] ; Moves index 2 into ax
```

- This is the same as `[arr + index * type arr]`

### Indirect addressing - Using a memory location
- `offset arr` stores the offset from .data segment.
	- This is faster than direct addressing because you don't have to calculate the offset again and again.t

```asm
.data
	arr1 word 0, 1, 2, 3, 4
.code
	mov eax, offset arr1
	add eax, type arr1 * 2   ; eax holds the offset of arr1 from .data
	mov bx, [eax]            ; Moves 2 into bx
```

## .code
- Des and src can never both be memory.
- `nop` - 1 byte of program storage and does nothing.
- `mov des, src` - Moves src to des without changing bits. Des and src have to be the same size.
- `movzx des, src` - Des has to be larger than src and fills in the upper bits with 0s.
- `movsx des, src` - Des has to be larger than src and fills in the upper bits with the sign of src.
- `xchg des1, des2` - Swaps des1 and des2. They have to be the same size.
	- Ex: Swap var1 and var2. `mov eax, var1`, `xchg eax, var2`, `mov var1, eax`

### Modifying flags

| Command                            | Description                      |
|------------------------------------|----------------------------------|
| `test des, 0`                      | Set Zero flag                    |
| `or des, 1`                        | Clear Zero flag                  |
| or most significant bit with 1     | Set Sign flag                    |
| and most significant bit with 0    | Clear Sign flag                  |
| `stc`                              | Set Carry flag                   |
| `clc`                              | Clear Carry flag                 |
| Add positive nums that produce neg | Set Overflow flag                |
| `or des, 0`                        | Clear Overflow flag              |
| `test reg, reg`                    | Check the flags without changing |

- `lahf` - Load the low byte of eflags into ah. This includes the sign, zero, auxiliary carry, parity, and carry flags.
- `sahf` - Store ah into eflags.

### Arithmetic
- `neg des` - Reverse the sign by using 2s compliment
	- Same as `sub 0, eax`
	- For all values except 0, the CF value is set.

#### Addition and Subtraction
- `add des, src`
- `sub des, src`
	- `des = des - src`
- `inc des` - Increments des. Faster than `add des, 1`
	- Doesn't effect the carry flag.
- `dec des` - Decrements des. Faster than `sub des, 1`
	- Doesn't effect the carry flag.
- Extended addition and subtraction - Adding/Subtracting any size ints.
	- `adc des, src` - Add with carry. des = des + src + CF
	- `sbb des, src` - Subtract with borrow. des = des - src - CF

#### Multiplying
- Multiplicand * Multiplier = Product

| Multiplicand | Multiplier  | Product   |
|--------------|-------------|-----------|
| al           | reg8/mem8   | ah:al(ax) |
| ax           | reg16/mem16 | dx:ax     |
| eax          | reg32/mem32 | edx:eax   |

- `mul des` - Unsigned multiplication.
	- CF set if the upper half of the product is not 0. Used to see if the upper half is needed.
- `imul des` - Signed multiplication.
	- OF set if the upper half of the product is not the sign bit(0000... or FFFF...) of the lower half.
	- Multi argument IMULs
		- Truncate the product to the length of the des
		- `imul reg16, reg16/mem16/imm8/imm16`
		- `imul reg32, reg32/mem32/imm8/imm32`
		- `imul reg16, reg16/mem16, imm8/16`
			- des1 = des2 * src

Ex: 16 * 16 or 10h * 10h
```asm
mov al, 10h
mov bl, 10h
mul bl         ; ah = 01h and al = 00h
```

#### Dividing
- Dividend / Divisor = Quotient

| Dividend  | Divisor     | Remainder | Quotient |
|-----------|-------------|-----------|----------|
| ah:al(ax) | reg8/mem8   | ah        | al       |
| dx:ax     | reg16/mem16 | dx        | ax       |
| edx:eax   | reg32/mem32 | edx       | eax      |

- `div des` - Unsigned division
	- OF is set if the quotient won't fit into the des.
- `idiv des` - Signed division.
	- You need to sign extend the upper half of the dividend.
		- `cbw` - Sign extends al to ah. Convert byte to word.
		- `cwd` - Sign extends ax to dx. Convert word to dword.
		- `cdq` - Sign extends eax to edx. Convert dword to qword.
		- Don't use because it is type dependent.

Ex: 16 / 16 or 10h / 10h
```asm
mov al, 10h
mov ah, 0
mov bl, 10h
div bl         ; ah = 00h and al = 01h
```

#### Bitwise
- `or des, src`
	- Union(what's in either set) of 2 sets
- `and des, src`
	- Intersection(what's the same between sets) of 2 sets
- `not des`
- `xor des, src`
	- Difference is good
	- 1 if different and 0 if the same.
	- Xor with 0 allows you to check the parity of a number without changing it.
- `nand des, src`
- `nor des, src`
- Setting, clearing, and toggling bits
	- `temp |= 0x4` - Sets to 1
	- `temp &= ~0x4` - Sets to 0
	- `temp ^= 0x4` - Toggles bit

Ex: Converting to upper case
```asm
mov eax, 61h    ; 'a'
and eax, NOT 32 ; 'A'
```

#### Shifting and Rotating
- `shl des, imm8/cl`/`sal des, imm8/cl` - Shift left.
	- Incoming bits are 0.
	- Shifting left by N bits multiples the int by 2^N.
- Shifting right
	- Shifting right by N bits divides the int by 2^N, always rounding down(-12.25 -> -13 and 12.25 -> 12).
	- `shr des, imm8/cl` - Logical shift right.
		- Incoming bits are 0.
		- Shifting right by N bits divides the int by 2^N, always rounding down.
			- Ex: -12.25 -> -13, but 12.25 -> 12
	- `sar des, imm8/cl` - Arithmetic shift right.
		- Incoming bits are the sign bit of des.
- Multi-des shifting
	- `shld reg16/mem16/reg32/mem32, reg16/reg32, imm8/cl` - Shift left into des1
		- The most significant bits of des2 are used to shift into des1.
	- `shrd reg16/mem16/reg32/mem32, reg16/reg32, imm8/cl` - Shift right into des1
		- The least significant bits of des2 are used to shift into des1.
	- Doesn't modify des2
- Rotating - The outgoing bit becomes the incoming bit.
	- `rol des, imm8/src` - Rotate left
	- `ror des, imm8/src` - Rotate right
	- `rcl des, imm8/src` - Rotate left through the Carry Flag
	- `rcr des, imm8/src` - Rotate right through the Carry Flag
- Notes
	- CF is set by the last bit being shifted/rotated out.
	- OF is set if the shift/rotate by 1 bit causes the sign of the des to be reversed.
		- It's undefined when shifting/rotating by greater than 1 bit.

Ex: Sign extend a register
```asm
mov ax, -128     ; eax = ????FF80h
shl eax, 16      ; eax = FF800000h
sar eax, 16      ; eax = FFFFFF80h
```

Ex: 13 * 10 using shifting
13 * 10 = 13 * (2^3 + 2^1) = 13 * 2^3 + 13 * 2^1
```asm
mov al, 13
shl al, 3     ; 13 * 2^3
mov bl, 13
shl bl, 1     ; 13 * 2^1
add al, bl    ; 13 * 2^3 + 13 * 2^3 = 13 * 10
```

### Loops
- `loop label` - Decrements ecx, and then jumps to label if ecx isn't 0.

Ex: Loop through an array
```asm
.data
	arr1 word 0, 1, 2, 3
.code
	mov eax, 0               ; Accumulator
	mov esi, 0               ; Index
	mov ecx, lengthof arr1   ; Count
L1:
	mov ebx, arr1[esi * type arr1]   ; Move arr1[index] into temp(ebx). This isn't necessary, just an example.
	add eax, ebx                     ; Add temp(ebx) to accumulator
	inc esi                          ; Increment index
	loop L1                          ; Decrements ecx, and exits if ecx is 0.
```

### Procedures and the Stack
- Definitions
	- Stack frame - The portion of the stack allocated for a procedure.
		- From base pointer to stack pointer.
	- `ebp`(Base pointer) - Holds the address of the base of the procedure.
		- Usually points to the previous procedure's base pointer.
	- `eip`(Instruction pointer) - Address of the next instruction.
	- `esp`(Stack point) - Points to the top of the stack, the last pushed stack value.
		- The stack moves into lower addresses(counts down), opposite from the data segment.
		- Points to the top of the previously pushed value.
	- Ways to return
		- Registers
		- .data variables
- Commands
	- `push src`
		- Moves esp down automatically by the type of src.
			- Can't push 1 byte types.
			- Not recommended to push 16 bits.
		- Moves the src into the stack.
	- `pop des`
		- Moves something on the stack into des.
		- Moves esp up automatically by the type of des.
			- Can't pop 1 byte types.
		- Can't pop into memory.
	- `call procedure` - Same as `push eip`
	- `ret` or `ret #` - Same as `pop eip`
		- `#` of bytes to pop from stack. Used to remove arguments.
	- `enter` - `push ebp`, then `mov ebp, esp`
		- Creating the stack frame for local variables.
	- `leave` - `mov esp, ebp` and `pop ebp`
		- Removing the stack frame
	- `pushfd`/`popfd`
		- Pushes/pops 32-bit eflags reg onto/off of the stack.
	- `pusha`/`pushad` and `popa`/`popad`
		- a - Pushes/pops 16 bit registers to/from the stack in AX, CX, DX, BX, SP, BP, SI, DI
		- ad - Pushes/pops 32 bit registers to/from the stack.
- Notes
	- Procedures can only reference labels in their own procedure unless it's a global label such as `label::`.
	- It's recommended to use Receives, Returns, and Requires when describing a procedure.
	- `Add proc uses esi ecx` - The uses operator pushes the listed register at the start of the procedure and then pops them at the end of the procedure.
		- You should resort any registers to their original values as long as they aren't being used as return values.
	- Link library - File containing procedure that have been assembled to object files.

```C++
int add(int x, int y) {
	int c;
	int d;
	c = 16;
	d = x;
	return x + y;
}

int main() {
	int c = add(10, 15);
}
```

```asm
main proc
	; Push arguments in reverse order
		push 15
		push 10
	call add    ; push eip to save the return address
	; Remove arguments
		add esp, 8
main endp

add proc
	; Stack formation
		enter 0, 0
			; or
		push ebp                    ; Save the parent procedure's base pointer
		mov ebp, esp                ; Create this procedure's stack frame
	; Inside the procedure
		sub esp, 8                  ; Creates uninitialized c and d(4 bytes each) variables
		mov [ebp - 4], 16           ; c = 16
		mov [ebp - 8], [ebp + 8]    ; d = x(+4 for eip and +4 to get to top of x)
		mov eax, [ebp + 8]
		add eax, [ebp + 12]
	; Return preparation
		leave
			; or
		mov esp, ebp                ; Remove local vars
		pop ebp                     ; Restore calling procedure's base pointer
	; Returning
		ret
			; or
		ret #                       ; # of bytes of arguments
add endp
```

### Calling conventions
- C calling convention
	- Arguments pushed in reverse order
	- After the call, the caller adds the bytes to the stack to remove the pushed arguments.
		- Allows for a variable number of arguments.
- stdcall convention - Used by Windows API
	- Arguments pushed in reverse order
	- Callee adds to the stack to remove argument.
- `lea des, src` - Load effective address. Returns the address of an indirect operand.
	- Ex: `lea eax, [ebp - 4]` does the same thing as `mov eax, ebp` and `sub eax, 4`, but only takes one operation.
	- `OFFSET` only works for addresses know at compiler time, while `lea` works at run time.
	- Usually only used to get address of stack memory.
- `LOCAL label1:type, label2:type, etc`
	- Can have multiple labels that are separated by commas.
	- Must appear immediately following the PROC.
	- Ex: `LOCAL var1:byte`, `LOCAL pArray:ptr word`, or `LOCAL TempArray[10]:dword`
	- Creates the stack frame, then moves esp to fit all the local variables, it forces the local variables to be 4 bytes so it stays align.
		- When you call a local variable, it automatically calculates it's offset from ebp.
- `INVOKE procedureName, arg1, arg2, etc`
	- Pushed arguments on the stack in reverse order, then calls the procedure.
	- Only in 32 bit mode.
	- You cannot call a procedure that has parameter names. You can only use INVOKE.
- `ADDR data`
	- Can only be used with INVOKE.
	- Passes the address of data. Similar to using OFFSET, but OFFSET can't work in INVOKE.
- `procedureName PROC uses registers, paramName:type, etc`
	- When using the paramName, it automatically calculates teh offset from ebp.
	- Does not push the arguments for you. That still has to be done by the caller.
- `procedureName PROTO`
	- Declare a procedure's name and parameter list before defining it.
- You can use the stack to reverse a string.

```asm
mov eax, [array]
vs
mov eax, array
mov eax, dword ptr [array]
```

### Jumps and Conditions
- `jmp label` - Jumps the code to that label
- `cmp des, src` - Subtracts to set the flags register, but doesn't change the des.
- `test des, src` - ANDing to set the flags register, but doesn't change the des.
	- Used to check if a bit is set.
		- Ex: `bool isSet = var1 & 0x4`
- Jump based on flags
	- `jz label`/`je label` - Jump if equal/zero flag
	- `jnz label, jne label` - Jump if not equal/zero flag
	- `js label` - Jump if sign flag
	- `jns label` - Jump if not sign flag
	- `jc` - Jump if carry flag
	- `jnc` - Jump if not carry flag
	- `jo` - Jump if overflow flag
	- `jno` - Jump if not overflow flag
- C register
	- `jcxz label` - Jump if CX = 0
	- `jecxz label` - Jump if ECX = 0
	- `jrcxz label` - Jump if RCX = 0 (64-bit mode)
- Unsigned
	- `jb label`/`jnae label` - Jump below.
		- ZF = 0 and CF = 1
	- `ja label`/`jnbe label` - Jump above.
		- ZF = 0 and CF = 0
	- `jae label`/`jnb label` - Jump above or equal.
	- `jbe label`/`jna label` - Jump below or equal.
- Signed
	- `jl label`/`jnge label` - Jump less.
		- SF not = OF
	- `jg label`/`jnle label` - Jump greater.
		- SF = OF
	- `jle label`/`jng label` - Jump less or equal.
	- `jge label`/`jnl label` - Jump greater or equal.
- Conditional loops
	- `loopz label`/`loope label` - Decrement ecx, loops if ecx isn't 0, or loop if zero/equal flag is set.
	- `loopnz label`/`loopne label` - Decrement ecx, loops if ecx isn't 0, or loop if zero/equal flag is clear.
- C to asm
	1. Determine if it's signed or unsigned.
	2. `&&`
		- If the condition is false(opposite conditional jump), jump to the next check.
	2. `||`
		- If the non-last condition is true(same conditional jump), jump to the body.
		- If the last condition is false(opposite conditional jump), jump to the next check.
	3. Non conditional jump to the end at the end of code blocks.
	- Label names
		- `If_Body_`, `Else_`, `Else_If_1_`, `Else_If_2_`, `End_If_`
		- `Or`, `Or_2`
		- `While`, `While_Body`, `End_While`

Ex: C If-Else to asm
```C
int a = 15;
int b = 10;

int main() {
	if (a == 1 && b > 1) {
		// Code block 1
	} else if (a <= 1 || b >= 1) {
		// Code block 2
	} else {
		// Code block 3
	}
}
```

```asm
.data
	a sdword 15
	b sdword 10
.code
	; if (a == 1 && b > 1)
	cmp a, 1
	jne Else_If_1
	cmp b, 1
	jng Else_If_1
If_Body:
	; Code block 1
	jmp End_If
Else_If_1: ; (a <= 1 || b >= 1)
	cmp a, 1
	jle Else_If_1_Body
	cmp b, 1
	jl Else_
Else_If_1_Body:
		; Code block 2
		jmp End_If
Else_:
	; Code block 3
	jmp End_If ; Not necessary
End_If:
```

Ex: While loop example
```asm
.data
	a sbyte 10
.code
While: ; (a >= 10)
	cmp a, 10
	jl End_While
	; Code body
	jmp While
End_While:
```

#### Conditional directives
- These only work in 32-bit mode, not 64-bit mode.
- These directives generate code, so they work at run time.
- Don't use in class.

| Directive         | Description                                 |
|-------------------|---------------------------------------------|
| .IF condition     |                                             |
| .REPEAT           | Repeats code until .UNTIL condition is met. |
| .UNTIL condition  | Placed at the end of .REPEAT                |
| .UNTILCXZ         | Until CX equals zero                        |
| .WHILE condition  |                                             |
| .ELSE             |                                             |
| .ELSEIF condition |                                             |
| .ENDIF            |                                             |
| .ENDW             | Placed at the end of a .WHILE               |
| .BREAK            | Terminates a .WHILE or .REPEAT              |
| .CONTINUE         | Jumps to top of .WHILE or .REPEAT           |

- The regular C syntax can be used for conditions, but you can also use these commands that return true depending upon the flag value.
	- `CARRY?`
	- `OVERFLOW?`
	- `PARITY?`
	- `SIGN?`
	- `ZERO?`
- The assembler generates asm code based upon if the variable is signed or unsigned.
	- The assembler defaults to unsigned if registers are compared.

### System calls
- Use to call the OS to do something specific such as writing out to the console.
	- Arguments are pass via specific registers per command.
	- Page 156

Non-standard system calls:
| Name              | Description                                       |
|-------------------|---------------------------------------------------|
| call WriteBin     | Prints out what's in eax to the console in binary |
| call WriteDec     | Prints out unsigned int in eax                    |
| call WriteInt     | Prints out signed int in eax                      |
| call WriteChar    | Prints out ascii char in eax                      |
| call crlf         | Prints out new line to the console. `0dh, 0ah`  |
| call WriteString  | Prints array until 0. `mov edx, offset str`       |
| call SetTextColor | Allows you to set the text color                  |
| call ClrScr       | Clears the screen                                 |

## Recursion
```C
// Recursive
int fact(int n) {
	if (n == 1) return 1
	return n * fact(n - 1);
}
// Iterative
int fact(int n) {
	int value = 1;
	for (int i = 1; i <= n; i++) {
		value *= i;
	}
	return value;
}
```

## Special array commands
- Move
	- Pointers to data in esi(source) and edi(destination).
	- Increments/decrement esi and edi by the type(byte, word, dword).
		- Increments if direction flag(DF) is 0
		- Decrements if direction flag(DF) is 1
		- `cld` - Clear direction flag. `std` - Sets direction flag
	- `movsb` - For bytes
	- `movsw` - For words
	- `movsd` - For dwords

Move all the elements in arr1 into arr2
```asm
.data
	arr1 dword 20 DUP(?)
	arr2 dword 20 DUP(?)

.code
	cld    ; Forward direction
	mov esi, OFFSET arr1
	mov edi, OFFSET arr2
	mov ecx, LENGTHOF arr1
	rep movsd             ; Repeats for the amount in ecx. Decrements ecx each time.
```

- Cmp
	- Compares the dereferenced value in esi and edi
	- `cmpsb`
	- `cmpsw`
	- `cmpsd`
	- `repe`/`repz` - Repeat if equal/zero flag.
	- `repne`/`repnz` - Repeat if not equal/not zero flag.
	- Still increments/decrements even if it doesn't repeat.

```asm
.code
	mov esi, OFFSET arr1
	mov edi, OFFSET arr2
	mov ecx, LENGTHOF arr1
	repe cmpsd                ; Still increments/decrements even if it doesn't repeat.
	sub esi, 4                ; Therefore you need to decrement.
	mov dword prt [esi], 100  ; Moves 100 into the position that didn't match the other array.
```

- sca - Scan
	- Compares a value in al/ax.eax to a byte, word, or dword that is dereferenced by edi.
	- `scasb`
	- `scasw`
	- `scasd`

```asm
mov edi, OFFSET str
mov al, 'F'
mov ecx, LENGTHOF str
cld
repne scasb
jnz quit               ; Didn't find anything
dec edi                ; Need to decrement to get the address of the F because repne still increments even if it didn't find anything.
```

- sto - Store. Put info in mem.
	- Used to init an array.
	- Moves the value in al/ax/eax into the address in edi
	- Increments/decrements edi by byte/word/dword
	- `stosb`
	- `stosw`
	- `stosd`

```asm
.data
	arr1 dword 20 DUP(?)
.code
	mov eax, 40h
	mov edi, offset arr1
	mov ecx, LENGTHOF arr1
	cld
	rep stosd
```

- lod - Load. Read info from mem.
	- Moves the dereferenced value in esi into al/ax/eax
	- Increments/decrements esi by byte/word/dword
	- `lodsb`
	- `lodsw`
	- `lodsd`

## Caching
- Law of locality - The memory closer to the CPU, the faster it is.
	- Web servers -> Local disks -> main memory(DRAM) -> L3 cache(SRAM) -> L2 cache -> L1 cache -> registers.
		- The CPU checks each layer to see fi it can find the data. If it does find the data, it copies around that data and puts it up the layer in order to avoid cache misses in the future.
	- If it becomes larger, it becomes slower because it's further away.
	- **Cache** - A smaller, faster storage device as a staging area for a larger slower storage device.
		- Usually the larger storage device is cheaper.
- CPU asks the cache for the value inside an address.
- The cache splits the address into tag, series, and offset(block address)
	- Tag = 1st 14 bits, series = 4 bits, offset = last 14 bits
	- Block size is 2^14 bytes
- The cache uses the series as an index for it's row.
	- The series chances per layer of cache.
- The cache linearly searches the lines in the row/series for a valid tag
- The cache uses the offset to find the value for the given address.
- If the cache cannot find a valid tag in the row/series, then it searches the next cache layer up. This is called a cache miss.
	- Once it finds that memory, then it copies the line to the lower cache layer and it overrides the line which was used the least.

```c
int aLen = 2^14 / 4;
int a[aLen];
int bLen = aLen + 1;
int b[bLen];

for (int i = 0; i < aLen; i++) {
	a[i] = 10;
}

// This will cache miss the last index.
for (int i = 0; i < bLen; i++) {
	b[i] = 10;
}

```