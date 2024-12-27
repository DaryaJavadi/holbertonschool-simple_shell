# Simple Shell Project
![Holberton school logo](https://i.pinimg.com/originals/c5/a6/d4/c5a6d4a0d33151ac29bfe66d2cfd4ab1.png)

## Description
The Simple Shell project is an implementation of a basic Unix command. This shell allows users to execute commands, navigate the file system, and run programs in both interactive and non-interactive modes.

## Features
- Interactive and non-interactive modes.
- Error handling and environment manipulation.
- This program displays a prompt and waits that the user types a command. A command line always ends with a new line (when user push *ENTER* key).
- The prompt is displayed again each time a command has been executed.
- When the user enters exit, *Hell shell* will end and returns the status 0.
- When the user enters exit *[status]*, *Hell Shell* will end and returns the inputted status, where *status* is a value from 0 to 255. 
- The user could stop the program using *Ctrl+D* (end of file).
- The shell handles the command lines with arguments and pathways.

## Requirements
- Ubuntu 20.04 LTS
- GCC compiler with options: `-Wall -Werror -Wextra -pedantic -std=gnu89`
- Betty style checker

## Usage
### Authorized functions and macros:
- access (man 2 access)
- chdir (man 2 chdir)
- close (man 2 close)
- closedir (man 3 closedir)
- execve (man 2 execve)
- exit (man 3 exit)
- _exit (man 2 _exit)
- fflush (man 3 fflush)
- fork (man 2 fork)
- free (man 3 free)
- getcwd (man 3 getcwd)
- getline (man 3 getline)
- isatty (man 3 isatty)
- kill (man 2 kill)
- malloc (man 3 malloc)
- open (man 2 open)
- opendir (man 3 opendir)
- perror (man 3 perror)
- read (man 2 read)
- readdir (man 3 readdir)
- signal (man 2 signal)
- stat (__xstat) (man 2 stat)
- lstat (__lxstat) (man 2 lstat)
- fstat (__fxstat) (man 2 fstat)
- strtok (man 3 strtok)
- wait (man 2 wait)
- waitpid (man 2 waitpid)
- wait3 (man 2 wait3)
- wait4 (man 2 wait4)
- write (man 2 write)

### Compilation

```bash
gcc -Wall -Werror -Wextra -pedantic *.c -o hsh
