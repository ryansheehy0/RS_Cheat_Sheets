[Home](../../README.md#tools)

# Bash Scripting

Bash scripting is creating a file with a sequence of bash commands which allow for automating tasks on linux.

Add `#!/bin/bash` to the start of bash script files. Bash script files what the .sh extension.

`#`s are comments in bash

<!-- TOC -->

- [Running](#running)
- [Variables](#variables)
- [Special parameters](#special-parameters)
- [Math](#math)
- [If statements](#if-statements)
	- [Conditionals](#conditionals)
- [Exit](#exit)
- [Reading user input](#reading-user-input)
- [While](#while)
- [For loop](#for-loop)
- [Case statements](#case-statements)
- [Running other scripts](#running-other-scripts)

<!-- /TOC -->

## [Running](#bash-scripting)
- To run a bash script first make it an executable. `sudo chmod +x script.sh`
- Then either run `./script.sh` or `. ./script.sh`
  - `./script.sh` just runs the script
  - `. ./script.sh` is the same as `source ./script.sh`. This allows the variables to be used after the script is ran.

## [Variables](#bash-scripting)
Variables in bash are case sensitive.

It is convention to use camel case in bash for variable names.

- `"`s allow for special characters like `${}`
- `'`s don't allow for special characters like `${}`

```bash
var="Ryan"

echo "hello $var"
echo "all uppercase ${var^^}"
echo "all lowercase ${var,,}"
echo "length of var: ${#var}"

# variable:offset:length
nums=0123456789
echo ${nums:2:3} # 234
echo ${nums: -4:4} # 6789

# To run commands and get the output you can use $()
currentDir=$(pwd)
```

- You can use 1 or 0 for boolean variables
- When working with file path variables make sure to put them inside `"$var"`s so that spaces don't effect the execution of commands.

## [Special parameters](#bash-scripting)
Special parameters are parameters set by the shell itself.

| Parameter   | Description                                                                     |
|-------------|---------------------------------------------------------------------------------|
| $#          | Number of arguments passed to the script                                        |
| $0, $1, ... | Represents each argument passed to the script. $0 is the name of the script ran |
| $$          | Process id of the current script                                                |
| $?          | The exit status of the last executed command                                    |

## [Math](#bash-scripting)

```bash
x=4
y=8
echo $((x+y)) #12

# No negative numbers or decimals
```

- List a sequence of numbers

```bash
echo month{1...3} # month1 month2 month3
```

- You can use C style math calculation using `(())`
  - Using `$(())` allows you to return the math that was done inside
  - Doesn't handle floats, only ints

```bash
(( a = (8*8 + 36)/2))
echo $a #50
echo $((++a)) #51

# Exponents
echo $((2**3)) #8

# $ return the value even when assigning to a variable
b=$((a = 15))
echo $b #15
```

## [If statements](#bash-scripting)

```bash
# Has to be a space between the condition and the brackets
if [[ condition ]]; then
    # Commands to be executed if the condition is true
elif [[ condition ]]; then
    # Commands to be executed if the condition is true
else
    # Commands to be executed if the condition is false
fi
```

### [Conditionals](#bash-scripting)

| Conditional   | Description                  |
|---------------|------------------------------|
| -eq or ==     | Equal                        |
| -ne or !=     | Not equal                    |
| =~ Regex      | If equal to the regex        |
| -lt or \<     | Less than                    |
| -le or \<=    | Less than or equal to        |
| -gt or >      | Greater than                 |
| -ge or >=     | Greater than or equal to     |
| !             | Logical not                  |
| -z            | True if string is empty      |
| -a  or &&     | Logical and                  |
| -o  or \|\|   | Logical or                   |
| -f "fileName" | true if the file exists      |
| -d "dirName"  | true if the directory exists |

## [Exit](#bash-scripting)
Use `exit #` to exit the script.

A non-zero status indicates an error, and 0 indicates a success.

## [Reading user input](#bash-scripting)

```bash
# This takes multiple inputs
read varA varB
echo "varA: ${varA}"
echo "varB: ${varB}"

read -p "Please enter variable A: " varA

# Allow for tab autocompletion
read -ep "Please enter a file path: " varB
```

## [While](#bash-scripting)

```bash
num=10

while [[ condition ]]; do
  # bash
  break
  continue
done
```

## [For loop](#bash-scripting)

```bash
for i in {1...5}; do
  # bash
  break
  continue
done
```

## [Case statements](#bash-scripting)

```bash
case $var in
  "value1")
    echo "It's value1";;
  "value2" | "value3")
    echo "It's value2 or value3";;
  [0-9]*) # you can so use regex
    echo "This stats with a digit";;
  *)
    echo "It's something else";;
esac
```

## [Running other scripts](#bash-scripting)
This allows you to run another script from your script that's in the same directory.

```bash
current_dir=$(dirname "$0")
"$current_dir"/script.sh
```