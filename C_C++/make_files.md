[Home](../README.md)

# Make files
Make files are used to automate the compiling of a project. It allows you to compile just the changed files instead of re-compiling everything.
- This is most often used for C style languages.

Example: * means a file has changed.
```
+--------------+      +---------------+
|  *file1.c    |      |    file2.c    |
+--------------+      +---------------+
       |       Compiler       |
       v                      v
+--------------+      +---------------+
|  *file1.o    |      |    file2.o    |
+--------------+      +---------------+
        \                     /
          \     Linker      /
            \             /
              v         v
           +---------------+
           |  *executable  |
           +---------------+
```

## [Steps for creating](#make-files)
1. Create a file called `makefile` or `Makefile`
1. Add rules
1. Run `make` when ready to compile

## [Comments](#make-files)
Comments start with #

## [Rules](#make-files)
If any of the dependencies change, then the commands are run to regenerate the target.

```
target: dependencies
	command
```

- Tabs have to be used instead of spaces for the indentation.
- Having an extra tab will throw an error.

## [Clean](#make-files)
There is often a clean target that usually removes the .o files and the executable. This is ran by doing `make clean`

```
clean:
    rm -f *.o executable
```

## [Variables](#make-files)

|                  |              |
|------------------|--------------|
| VAR_NAME = value | Creating var |
| $(VAR_NAME)      | Using var    |

# [Conditional execution](#make-files)

```
ifeq ($(VAR_NAME), value)
    # code
else ifeq ($(VAR_NAME), value2)
    # code
else
    # code
endif
```

## [List of ifs](#make-files)

|        |                                     |
|--------|-------------------------------------|
| ifeq   | if equals                           |
| ifneq  | if not equals                       |
| ifdef  | if a variable is defined(non-empty) |
| ifndef | if a variable is not defined        |

# [Full Example](#make-files)

```
CC = gcc
CFLAGS =
LIBS =

executable: file1.o file2.o
    $(CC) $(CFLAGS) file1.o file2.o -o executable $(LIBS)

file1.o: file1.c
    $(CC) $(CFLAGS) -c file1.c $(LIBS)

file2.o: file2.c
    $(CC) $(CFLAGS) -c file2.c $(LIBS)

clean:
    rm -f *.o executable

```

Variables

`$()` Is used to de-reference variables.

| Variables | Description                                                   | Example                     |
|-----------|---------------------------------------------------------------|-----------------------------|
| `=`       | Verbatim assignment. Doesn't dereference variables.           | `VAR = val`                 |
| `:=`      | Simple expansion. Does dereference variables.                 | `VAR := $(VAR2)`            |
| `!=`      | Shell output into var                                         | `VAR != find . -name '*.c'` |
| `?=`      | If there isn't a variable then assign with value. Else don't. | `VAR ?= value`              |
| `+=`      | Append to                                                     | `VAR += another value`      |

You can have spacial keyboard to do things in `$()`.
- wildcard - Van be used to match files
    - Ex: `$(wildcard *.c)` gets all the .c files in the current directory
- shell - Allows you to run shell commands and capture their output.
    - Ex: `$(shell find . -name '*.c')` gets all the .c files in the current directly.
- word - 
- subst find,replace,text
- patsubst
- strip
- findstring
- filter
- sort
- dir
- notdir
- suffix
- basename
- addsuffic
- if
- or
- realpath
- abspath
- add, subtract, multiply, div
- $@, $<, $^, $+, $?, $*, $%
- .PHONY, .DEFAULT_GOAL, .SUFFIXES, .SILENT, .EXPORT_ALL_VARIABLES, .DELETE_ON_ERROR
- 