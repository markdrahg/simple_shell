# 🐚 Simple Shell

**Simple Shell** is a Unix command-line interpreter (shell) written in C. It mimics the behavior of traditional Unix shells by reading user commands, interpreting them, and executing the appropriate programs through the kernel.

## 🚀 Overview

This project is a minimalist implementation of a shell, built from scratch in C. It handles command-line input, parses arguments, searches for executable programs in the system `PATH`, and executes them. It also supports several built-in commands such as `exit`, `env`, and `cd`.

## ✨ Features

- Execution of user commands with arguments
- Implementation of key built-in commands:
  - `exit` – to exit the shell
  - `env` – to display the environment variables
  - `cd` – to change directories
- Command search via the system `PATH`
- Input parsing and argument tokenization
- Error handling and basic prompt display
- Supports interactive and non-interactive modes

## 🔧 How It Works

1. The shell displays a prompt.
2. It reads a line of input from the user.
3. The input is parsed into commands and arguments.
4. It checks if the command is a built-in.
5. If not built-in, it searches for the command in the system `PATH`.
6. Executes the command using `execve()` or reports an error.

## 🛠️ Compilation

To compile the shell:

```bash
gcc -Wall -Werror -Wextra -pedantic *.c -o hsh
./hsh
