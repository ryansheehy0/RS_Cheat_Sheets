[Home](../../README.md#tools)

# Linux Commands
Linux terminal commands

<!-- TOC -->

- [Pipes](#pipes)
- [Navigation](#navigation)
	- [Files types](#files-types)
- [Changing Permissions](#changing-permissions)
	- [usermod](#usermod)
- [Miscellaneous](#miscellaneous)
- [Installation](#installation)
- [Package Manager](#package-manager)
	- [Advanced package toolapt](#advanced-package-toolapt)
- [File and Directory Manipulation](#file-and-directory-manipulation)
- [Find](#find)
- [Computer commands](#computer-commands)
	- [ps, kill](#ps-kill)
	- [job, bg, fg](#job-bg-fg)
	- [Mount and Unmount drive](#mount-and-unmount-drive)
	- [Recursive size of folders in a directory](#recursive-size-of-folders-in-a-directory)
- [Compression](#compression)
	- [gzip](#gzip)
	- [tar](#tar)
		- [tar and gzip combined](#tar-and-gzip-combined)
	- [zip files](#zip-files)
- [sed](#sed)
- [awk](#awk)
- [Networking](#networking)
	- [ping](#ping)
	- [httprobe](#httprobe)
	- [curl](#curl)
- [grep](#grep)
- [sort and uniq](#sort-and-uniq)
- [head and tail](#head-and-tail)
- [Redirection operations](#redirection-operations)
- [alias](#alias)

<!-- /TOC -->

## [Pipes](#linux-commands)
Pipes allow you to input the output of one command into another.

`command1 | command2`

The outputs of command1 go into the inputs of command2

## [Navigation](#linux-commands)

| Command | Description                               |
|---------|-------------------------------------------|
| pwd     | List current directory                    |
| cd      | Change directory                          |
| ls      | Lists what is in the directory            |
| ls -a   | Lists with hidden files/directories shown |
| ls -l   | List in the long way                      |

```
-rwxrwxrw- 1 root ryan 9999 May 22 00:01 FileName
^[^][^][^] ^ [ ^] [^ ] [^ ] Date of creation
| |  |  |  |   |   |    |
| |  |  |  |   |   |   Size in bytes
| |  |  |  |   |   group
| |  |  |  |   user
| |  |  |  Number of links to this file
| |  |  public
| |  group
| user
File types
```

|   | Description     |
|---|-----------------|
| r | Allow reading   |
| w | Allow writing   |
| x | Allow executing |
| - | Not allowed     |

| Location | Description          |
|----------|----------------------|
| ./       | In current directory |
| ~        | Home directory       |
| ../      | One directory up     |

### [Files types](#linux-commands)

| File type | Description                                                                                             |
|-----------|---------------------------------------------------------------------------------------------------------|
| -         | Regular file                                                                                            |
| d         | Directory/Folder                                                                                        |
| l         | Symbolic link. A reference to another file or directory                                                 |
| c         | Character device. Device which transfers data as a steam of bytes. (Inputs can be found in /dev/input/) |
| b         | Block device. Devices which transfer data in fixed size blocks.                                         |
| p         | Named pipe. First in, First out, used for inter-process communication.                                  |
| s         | Socket. Communication endpoints for inter-process communication.                                        |
| w         | Whiteout. Used for union file systems to mark entries which should be hidden.                           |

## [Changing Permissions](#linux-commands)

| Command                     | Description                                                              |
|-----------------------------|--------------------------------------------------------------------------|
| chown user:group fileName   | Change user and group                                                    |
| chown -R user:group dirName | Recursively change the users and groups of al the files in the directory |
| chmod ### fileName          | Change permissions. r(4) w(2) x(1) -(0)                                  |
| chmod +x fileName           | Change file to be an executable                                          |

### [usermod](#linux-commands)
`usermod` is used to change account properties.

| Flags                      | Description                  |
|----------------------------|------------------------------|
| -l newUsername oldUsername | Changes the username         |
| -u newUUID username        | Changes the User's id        |
| -g newGID username         | Changes primary group id     |
| -aG group username         | Adds the username to a group |

## [Miscellaneous](#linux-commands)

| Command              | Description                                               |
|----------------------|-----------------------------------------------------------|
| sudo                 | Run command as super user                                 |
| !!                   | Run previous command                                      |
| su user              | Switch to that user                                       |
| cat file             | Outputs contents of a file                                |
| cat - file           | The - is the input into the cat file                      |
| cat file \| less     | allows you to go through outputs one by 1                 |
| echo text            | Outputs text                                              |
| date                 | Show current date and time                                |
| ctrl + c             | Allows you to stop running the current program            |
| command1 && command2 | Run command1 and if that was successful than run command2 |
| command &            | Runs the command in the background                        |
| wc fileName          | Counts the number of lines, words, and bytes in a file    |
| wc -l                | Number of lines                                           |
| clear                | Clears the contents of the terminal                       |
| dirname filePath     | Gets the directory portion of a file path                 |

## [Installation](#linux-commands)

| Command                 | Description                 |
|-------------------------|-----------------------------|
| sudo dpkg -i ./file.deb | Install .deb files          |
| dpkg -l                 | List all installed packages |

## [Package Manager](#linux-commands)
- apt
  - debian based package manager
  - Installs .deb files which share dependencies
- Flatpak
  - A package manager for .flatpakref files
  - Packages applications and dependencies in the same place
  - Used for gui apps
- AppImage
  - A format for distributing portable software.
  - The application and the dependencies are combined.
  - The application is just 1 file
- Pacman
  - Arches package manager
- Snap
  - Umbutu's competitor to Flatpaks

Dependency hell is when one application needs an older version of a library than another application. You might have to install both the older version and the newer one.

### [Advanced package tool(apt)](#linux-commands)

| Command                      | Description                                                                            |
|------------------------------|----------------------------------------------------------------------------------------|
| sudo apt install packageName | Install packageName                                                                    |
| sudo apt remove packageName  | Uninstall packageName                                                                  |
| sudo apt update              | Update source list for packages. The source list can be found at /etc/apt/sources.list |
| sudo apt upgrade             | Updates all the installed packages                                                     |
| sudo apt search packageName  | Searches for packageName                                                               |
| sudo apt purge packageName   | Uninstalls and removes files of packageName                                            |
| sudo apt autoremove          | Removes all unneeded packages                                                          |
| sudo apt install --only-upgrade packageName | Only upgrade that package |

## [File and Directory Manipulation](#linux-commands)
Folders and directories are the same thing.

| Command                     | Description                                              |
|-----------------------------|----------------------------------------------------------|
| mkdir dirName               | Make directory                                           |
| mkdir folderPath/dirName    | Create a directory in another folder                     |
| touch fileName              | Make file                                                |
| rm fileName                 | Delete file                                              |
| rm -rf dirName              | Removes directory and everything within it               |
| rm dirName/*                | Removes everything in directory, but keeps the directory |
| cp fileName fileName2       | Renames fileName to fileName2                            |
| cp fileName ./Dir/          | Copies fileName to dir with same name                    |
| cp fileName ./Dir/fineName2 | Copies fileName to dir and renames it to fileName2       |
| cp -r dirName ./Dir/        | Recursively copies dirName into ./Dir/                   |
| cp -r dirName/* ./Dir/      | Recursively copies the contents of dirName into ./Dir/   |
| mv fileName destinationDir  | Moves file to destination directory                      |
| mv ./* dirPath              | Move all contents of current folder to another directory |
| gio trash dirName/          | Moves directory or file to trash.                        |

## [Find](#linux-commands)
Used for finding files or directories

| Command                          | Description                                                  |
|----------------------------------|--------------------------------------------------------------|
| find filePath -iname "fileName*" | Finds files under filepath. Case insensitive                 |
| -type f                          | Only shows files                                             |
| -type d                          | Only shows directories                                       |
| -mmin -10                        | Find files that were modified less than 10 minutes ago       |
| -mmin +10                        | Find files that were modified more than 10 minutes ago       |
| -mtime -10                       | Find files that were modified less than 10 days ago          |
| -size +5M                        | Files over 5 megabytes                                       |
| -empty                           | Empty files                                                  |
| -perm ###                        | Find files with that permission                              |
| -maxdepth #                      | Sets a max depth for recursive searching through directories |
| -exec command                    | Executes a command on all of the files                       |

Examples:
- `find . -type f -exec chown user:group {} \;` Recursively changes the owner of each file in a directory.
- `find . -type f -maxdepth 1 -name "*.jpg" -exec rm {} \;` Removes all .jpg files from a directory.

## [Computer commands](#linux-commands)

| Command              | Description                                     |
|----------------------|-------------------------------------------------|
| sudo reboot          | Restart computer                                |
| sudo shutdown -h now | Shutdown's computer                             |
| lspci -k             | List drivers                                    |

### [ps, kill](#linux-commands)
ps is used to show different process running.

| Command                | Description                                     |
|------------------------|-------------------------------------------------|
| ps                     | List processes running in that terminal session |
| ps -x                  | All process on that user                        |
| ps -He                 | Hierarchical relationships of processes         |
| ps -axjf               | More advanced view                              |
| ps -aux                | Shows users, cpu%, mem%, and other stuff        |
| kill PID               | Terminate(ask program to shut down) process     |
| kill -9 PID            | Kill(force a program to shut down) a program    |
| killall programName    | Terminate all processes with that name          |
| killall -9 programName | Kill all processes with that name               |

### [job, bg, fg](#linux-commands)

| Commands  | Description                                                |
|-----------|------------------------------------------------------------|
| ctrl + z  | Suspend/Pause program                                      |
| jobs      | List all the paused programs and their number(on the left) |
| fg jobNum | Runs a job in the foreground                               |
| bg jobNum | Runs a job in the background                               |
| command & | Run command in the background                              |

### [Mount and Unmount drive](#linux-commands)
With some linux distros this happens automatically

1. Plug in drive
1. `sudo fdisk -l` find where drive is
1. `sudo mount filePathFromFdisk filePathMountFolder` mounts the drive
1. `sudo umount filePathMountFolder` unmounts the drive

### [Recursive size of folders in a directory](#linux-commands)

`du --max-depth=1 -h ./`

## [Compression](#linux-commands)

### [gzip](#linux-commands)
gzip is used to compress only 1 file at a time.

| Command              | Description                                               |
|----------------------|-----------------------------------------------------------|
| gzip -k fileName.txt | Compresses one file with .gz and keeps the original file. |
| gzip -d fileName.gz  | Decompresses a .gz file                                   |

### [tar](#linux-commands)
tar is used to create an archive, a grouping of multiple files into a single file.

| Command                         | Description                          |
|---------------------------------|--------------------------------------|
| tar -cf archive.tar file1 file2 | Create an archive called archive.tar |
| tar -xf archive.tar -C dirPath  | Extracts a .tar file                 |
| tar -tf archive.tar             | View what's in a .tar file           |

| Flags        | Description                       |
|--------------|-----------------------------------|
| -c           | Create an archive.                |
| -f           | Specify the name of the archive   |
| -x           | Extract an archive                |
| -t           | Just view what's in the archive   |
| -C directory | Specifies an extraction directory |

#### [tar and gzip combined](#linux-commands)

| Command                             | Description                                 |
|-------------------------------------|---------------------------------------------|
| tar -czf archive.tar.gz file1 file2 | Create an archive and compress it with gzip |
| tar -xf archive.tar.gz -C dirPath   | Extracts a .tar.gz file                     |

### [zip files](#linux-commands)
`unzip` is used to decompress .zip files

| unzip Flags    | Description                                       |
|----------------|---------------------------------------------------|
| -t             | Test if any of the files are corrupted            |
| -d folder name | Specify the name of the folder to decompress into |
| -q             | Doesn't output anything. Quiet                    |

Examples:
- `unzip -qd FolderName compressed.zip`
  - Decompresses a .zip file
- `zip -r compressionName.zip dirPath`
  - Compresses files as a .zip file

## [sed](#linux-commands)
Stream editor which is used to find and replace things inside files using regex.

sed {options} {script} {optional file}

| Options   | Description                                                                                           |
|-----------|-------------------------------------------------------------------------------------------------------|
| -n        | Prints lines that match that pattern.                                                                 |
| -e        | Allows multiple find and replaces to a file. `sed -e 's/find/replace/' -e 's/find/replace/' filename` |
| -i        | Allows modifying the files directly.                                                                  |
| -i.backup | Creates backup before modifying the file.                                                             |

| Scripts                       | Description                                                                          |
|-------------------------------|--------------------------------------------------------------------------------------|
| s/ {regex} / {replacement} /  | Substitutes the first occurrence of the regex with the replacement text.             |
| s/ {regex} / {replacement} /g | Allows for more than one replacement on a line.                                    |
| / {regex} / {command}         | Runs the command only to the lines matching the regex.                               |
| / {regex} /d                  | Deletes the line that has the regex in it.                                           |
| {number}q                     | Prints the first number of lines of a file                                           |

- `#`s can also be used instead of the `/`s

```
sed -i.backup 's/foo/bar/g' file.txt
    Creates a backup called file.txt.backup and then replaces all occurrences of foo in file.txt to bar.

cat file.txt | sed 's/apple/orange/g'
    Replaces all occurrences of apple with orange and outputs it to the terminal. Doesn't change file.txt at all.

sed 's/o/O/g' <file1.txt >file2.txt
    Reads in file1.txt, replaces o for O, and outputs that into file2.txt. Doesn't change file1.txt

man sed | sed '/replace/s/the/The/g'
    The lines that have "replace" on them have the "the"s changed to "The"s.
```

## [awk](#linux-commands)
Awk is used to run a command on inputs that are separated by some pattern. The default field separator is a space. It can also be used to run commands on each line of a file.

Columns are defined with teh field separator. Rows are defined by new lines.

`$#` is used to choose which column. `$NF` is used to get the last column.

| Flags | Description                               |
|-------|-------------------------------------------|
| -F':' | Setting a custom field separator to be :s |

Examples:
- `awk '{print $2}' /inputFile.txt`
  - Prints the the 2nd column from inputFile
- `awk '{print $1,$NF}' /inputFile.txt`
  - Prints the the 1st column and the last column from inputFile
- `echo "[" && awk '{print "\""$1"\""","}' ./text.txt && echo "]" > text.json`
  - Converts a text file of lines of data into an array in a json file

## [Networking](#linux-commands)

### [ping](#linux-commands)
Ping is used to message a server and see if you are getting a response.

| Flags | Description                                   |
|-------|-----------------------------------------------|
| -c #  | Stops ping after a certain number of requests |

- You can use ip `8.8.8.8` which is google's dns server to check if you have an internet connection.
- Ping uses ICMP network requests and some servers maybe configured to block this traffic.

### [httprobe](#linux-commands)
httprobe is used to take a list of domains and probe for working HTTP and HTTPS servers.

`cat domains.txt | httprobe > results.txt`

### [curl](#linux-commands)
Used to get the return information from websites/apis. Makes a get request form a URL.

`curl https://api.github.com/users`

| Flags   | Description                                |
|---------|--------------------------------------------|
| -i      | Returns the headers and content            |
| -I      | Returns just the headers                   |
| -X HTTP | Used to make http commands other than GET. |

## [grep](#linux-commands)
Grep is used for searching text in a file. Grep returns the lines that match a pattern, or the files that contain the pattern.

`grep -Flags pattern fileName`

| Flags | Description                                                                    |
|-------|--------------------------------------------------------------------------------|
| -w    | Just match the word and not words which just contain the pattern               |
| -i    | Case sensitive                                                                 |
| -n    | Gives line number                                                              |
| -A #  | Shows # of lines after the line which has the pattern                          |
| -B #  | Shows # of lines before the line which has the pattern                         |
| -C #  | Shows # of lines before and after the line which has the pattern               |
| -r    | Recursively search through a directory                                         |
| -l    | Just show the files which contain the match                                    |
| -c    | Shows all files and how many matches are in that file.                         |
| -P    | Allows for Pearl compatible expressions. Allows \d and other regex expressions |
| -v    | Inverse match                                                                  |
| -h    | Don't display the file name. Just the lines                                    |
| -H    | Display the file name and the lines.                                           |

If you don't want to recursively search through a directory you can do `grep pattern dirPath/*`

Examples:
- `grep -wirn "grep" .` Searches for lines with the word "grep" recursively in the current directory
- `grep -wirl "grep" .` Searches for files that contain the word "grep"
- `grep -wirc "grep" . | grep -v :0$` Search for files that contain the word "grep" and how many matches they have to the word "grep"

## [sort and uniq](#linux-commands)
`sort` is used to sort an input by alphabetical order or numerical order.

| Flags | Description                |
|-------|----------------------------|
| -u    | Only outputs unique values |
| -n    | Numerical search           |
| -r    | Reverse sort               |

`uniq` omits repeated lines. By default uniq removes adjacent duplicated values.

| Flags | Description                                   |
|-------|-----------------------------------------------|
| -d    | Only print out the lines which has duplicates |
| -u    | Only displays lines which aren't duplicated   |
| -c    | Gives a count                                 |

uniq is often used with sort. Sort groups the same lines together and uniq removes duplicated lines.

Example:
`sort favFlavors.txt | uniq -c | sort -nr` Gets the favorite flavors from most popular to least

## [head and tail](#linux-commands)
`head` and `tail` are used to output on the first or last lines of a file.

| Flags | Description                         |
|-------|-------------------------------------|
| -n #  | Number of lines. The default is 10. |

## [Redirection operations](#linux-commands)

| Command           | Description                                                                               |
|-------------------|-------------------------------------------------------------------------------------------|
| command \> file   | Redirect the output of a command into another file. It overwrites everything in that file |
| command \>\> file | Append to the end of a file                                                               |
| command \< file   | Inputs the file into the command. You can also use `cat file \| command`                  |

- `<<` is used to input blocks of text into a command
  - The delimiter is any sequence of characters which marks the end of the input block
```bash
# This will input the lines "Input line 1." and "Input line 2." into the command and the command will treat it as an input file.
command << delimiter
Input line 1.
Input line 2.
delimiter
```

- You can run this to append to the beginning of a file
```bash
echo "Append to beginning" | cat - file.txt > temp && mv temp file.txt
```

## [alias](#linux-commands)
alias is used to create shortcuts to commands so you don't have to always type them out.

| Commands                   | Description                                                                                  |
|----------------------------|----------------------------------------------------------------------------------------------|
| alias                      | list your aliases                                                                            |
| alias aliasName='commands' | Create an alias. To have them persist across terminal instances put them in the .bashrc file |