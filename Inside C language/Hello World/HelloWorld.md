# Hello World

## Important Note
**It is recommended to review each exercise from first to last, as most of the work and skills must be acquired independently through practice.**

## Getting Started

### Prerequisites
- GCC compiler
- Text editor or IDE (VS Code recommended)
- Terminal/Command prompt access

### Installing GCC

**Windows (PowerShell):**
- Install MinGW or use Visual Studio Build Tools

**WSL/Linux:**
```bash
sudo apt update
sudo apt install gcc
```
# How to Compile and Run

**Windows (PowerShell):**
# Navigate to project directory
cd C:\Path\To\Your\Project

# Compile
gcc -Wall -O2 filename.c -o output_name

# Run
.\output_name

**WSL/Linux:**

# Navigate to project directory
cd /path/to/your/project

# Compile
gcc -Wall -O2 filename.c -o output_name

# Run
./output_name

## Compiler Flags Explained
- `-Wall` - Display all common warnings
- `-O2` - Optimization level 2 (compiler optimizes inefficient code)
- `-o output_name` - Specifies the name of the executable file

## Key C Concepts Covered

### Header Files
- `#include <stdio.h>` - Standard input/output functions
- `#include "filename.c"` - Include custom files
- Function prototypes and manual pages (`man 3 printf`)

### Main Function
- `int main()` - Function returning integer value
- `return 0` - Success indicator (Unix convention)
- Return values: 0 = success, 1,2,3... = various failure types

### Useful Terminal Commands

# Check program return value
```bash
echo $?

# Run program and show return value
./program; echo $?

# Conditional execution (runs ls only if program succeeds)
./program && ls

# Calculator mode
bc
```
# (type 'quit' to exit)

## File Structure
Each exercise builds upon previous concepts. Work through them sequentially for best learning outcomes.

## Alternative Approaches
You can also declare function prototypes manually instead of including headers:
```c
int printf(const char * restrict format, ...);
```
## File Structure
Each exercise builds upon previous concepts. Work through them sequentially for best learning outcomes.

## Alternative Approaches
You can also declare function prototypes manually instead of including headers:
```c
int printf(const char * restrict format, ...);
```
(Prototype can be found using man 3 printf)

## Best Practices

-Always include return 0 in main function
-Use meaningful variable names
-Comment complex logic
-Test with various inputs
-Use compiler warnings to catch errors early

## Notes

-puts("text") is equivalent to printf("text\n") and more performant for simple string output
-Modern C compilers don't require return 0 but it's good practice
-C++ requires explicit return statements
