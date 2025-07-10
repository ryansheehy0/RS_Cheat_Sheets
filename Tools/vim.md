[Home](../README.md#tools)

# Vim commands

<!-- TOC -->

- [Movement](#movement)
- [Save/Quit](#savequit)
- [Modes](#modes)
- [Delete](#delete)
- [Change](#change)
- [Undo and redo](#undo-and-redo)
- [Copy, Paste, and Cut](#copy-paste-and-cut)
- [Find on page/Search](#find-on-pagesearch)
	- [Special characters in replace](#special-characters-in-replace)
- [Macros](#macros)
- [Visual Modes](#visual-modes)
	- [Visual Line Mode](#visual-line-mode)
	- [Visual Block Mode](#visual-block-mode)
- [Markers](#markers)

<!-- /TOC -->

## [Movement](#vim-commands)

|            |                                          |
|------------|------------------------------------------|
| h          | left                                     |
| j          | down                                     |
| k          | up                                       |
| l          | right                                    |
| gg         | go to top                                |
| G          | go to bottom                             |
| w          | next word                                |
| b          | back a word                              |
| e          | Move to the end of a word                |
| : + number | go to line number                        |
| 0          | Move to beginning of line                |
| $          | Move to end of line                      |
| g + 0      | Beginning of line without the line break |
| g + $      | End of line without the line break       |
| zz         | Center cursor                            |
| ctrl + u   | Move up half a page                      |
| ctrl + d   | Move down half a page                    |

- A number can be placed in front of hjkl to move relative to the current line.
	- Ex: 10k moves up 10 lines relative to the current line.

## [Save/Quit](#vim-commands)

|      |                       |
|------|-----------------------|
| :w   | save                  |
| :q   | quit                  |
| :wq  | save and quit         |
| :wq! | force a save and quit |

## [Modes](#vim-commands)

|     |                              |
|-----|------------------------------|
| i   | insert mode                  |
| o   | insert line below and i mode |
| O   | insert line above and i mode |
| a   | insert to the right          |
| esc | back to command/normal mode  |
| v   | visual mode                  |

## [Delete](#vim-commands)

|    |                                               |
|----|-----------------------------------------------|
| dd | delete line and copy line to default register |
| x  | delete where your cursor is at                |

## [Change](#vim-commands)

|          |                |
|----------|----------------|
| c i w    | change in word |
| r        | replace letter |
| select U | Uppercase      |
| select u | Lowercase      |

## [Undo and redo](#vim-commands)

|          |                    |
|----------|--------------------|
| u        | undo               |
| ctrl + r | redo               |
| .        | redo command again |

## [Copy, Paste, and Cut](#vim-commands)

|          |                               |
|----------|-------------------------------|
| yy       | Copy line to default register |
| p        | Paste below default register  |
| P        | Paste above default register  |
| " char y | Copy to char register         |
| " char p | Paste from char register      |

- The + register is the system clipboard register

## [Find on page/Search](#vim-commands)

 |               |                                                            |
 |---------------|------------------------------------------------------------|
 | / regex enter | Search forward on page                                     |
 | ? regex enter | Search backward on page                                    |
 | n             | go to next instance                                        |
 | N             | go back one instance                                       |
 | :noh          | remove highlight                                           |
 | f + char      | Go to the next occurrence of that char in the current line |
 | F + char      | Go to prev occurrence of that char in the current line     |

### [Special characters in replace](#vim-commands)

|      |                                   |
|------|-----------------------------------|
| `\r` | New line                          |
| `\u` | Uppercase the following character |

## [Macros](#vim-commands)

|                    |                                                               |
|--------------------|---------------------------------------------------------------|
| q macroChar keys q | record keys and put it in macro char that can be played again |
| @ macroChar        | play the macro                                                |

## [Visual Modes](#vim-commands)

|          |                   |
|----------|-------------------|
| V        | Visual Line Mode  |
| ctrl + v | Visual Block Mode |

### [Visual Line Mode](#vim-commands)
- First select text in visual line mode then you can run these commands

|                    |                                                           |
|--------------------|-----------------------------------------------------------|
| <                  | Remove indent                                             |
| >                  | Indent                                                    |
| :s/regex/replace/g | Search and replace in selected text.                      |
| :s/\. /\. \r/g     | Split a line into multiple lines by periods.              |
| J                  | Combine lines into one line with a space between them.    |
| g J                | Combine lines into one line without a space between them. |
| :g/^$/d            | Remove empty lines from selected text.                    |

- \r is used as a new line in :s

### [Visual Block Mode](#vim-commands)
- First select text in visual block mode then you can run these commands

|                              |                                                     |
|------------------------------|-----------------------------------------------------|
| SelectBeginning I characters | Add characters in front of all the lines selected   |
| SelectEnd A characters       | Add characters at the end of all the lines selected |
| SelectNumbers ctrl + a       | Incrmeent numbers by 1                              |
| SelectNumbers ctrl + x       | Decrement numbers by 1                              |
| SelectNumbers g ctrl + a     | Progressively incrment. 1 2 3 4 etc.                |
| SelectNumbers g ctrl + x     | Progressively decrement. 4 3 2 1 etc.               |

## [Markers](#vim-commands)

|                |                                                       |
|----------------|-------------------------------------------------------|
| m char         | Set a marker at that line with the character          |
| ` char         | Jump to the character marker line                     |
| :delmarks char | Delete the character marker                           |
| :delmarks!     | Delete all lower case character markers for that file |

- Upper case markers are global markers that exist across files.
