# Custom C Shell

A minimalistic command-line interpreter (shell) written in C.

## Features
* **Process Management**: Executes external programs using `fork()`, `execvp()`, and `wait()`.
* **Built-in Commands**: Efficiently handles internal commands like `cd`, `help`, and `exit`.
* **Advanced Architecture**: Uses **X-Macros** to maintain a "single source of truth" for built-in command registration and mapping.
* **Custom Parser**: Includes a robust string tokenizer for handling command-line arguments.

## Project Structure
* `src/`: Implementation files (`.c`).
* `include/`: Header files (`.h`).
* `obj/`: Compiled object files.
* `Makefile`: Automated build system for Clang/GCC.

## Getting Started

### Prerequisites
* Clang or GCC compiler.
* Make build tool.

### Installation & Running
1. Clone the repository:
   ```bash
   git clone <your-repository-link>
   cd shell
   ```
2. Build the project
   ```bash
   make
   ```
3. Run the shell
   ```bash
   ./shell
   ```
## Usage 
Once the shell is running, you can use standard Linux commands:
* `ls -la`
* `mkdir new_folder`
* `cd include (Built-in)`
* `help (Built-in)`
* `exit (Built-in)`

## Technical Highlights: X-Macros

One of the key features of this project is the use of **X-Macros** in 'builtins.h'. This allows adding new built-in commands by modifying only one line in a table, automatically generating:

1. Function prototypes
2. Command name strings
3. Function pointer arrays

## License
MIT
