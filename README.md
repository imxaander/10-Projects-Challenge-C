# README for 10-Projects-Challenge-C
Welcome to the 10 Projects Challenge in C! This repository is a personal challenge to build 10 different projects using the C programming language and my own C library. Below are the projects completed so far, with a brief description for each:

## Projects
### Basic Command Line Calculator

#### Description: A basic command line arithmetic calculator that utilizes command line arguments (argc, argv).
#### Usage:
./imxcalculator <first_number> <_operator> <second_number>
<first_number>: The first operand (must be a valid number)

<_operator>: The operator for the operation (+, -, *, /)

<second_number>: The second operand (must be a valid number)

### IMXSHELL

#### Description: A custom Unix/Linux shell that supports basic commands (ls, cd, pwd, clear) and external applications located in the /bin/ directory.
#### Features:
Supports majority of commands available in a native Linux terminal.
Learning outcomes include exec() family, fork(), readdir, opendir, dirents, designated initializers, function pointers, and memory management (realloc, malloc).
Linkedlist Operations Implementation

#### Description: This project highlights linked list traversal, addition, and deletion of nodes within a linked list. It focuses on the application of C programming with pointers and recursion.


### RLE Binary File Compressor

#### Description: This C program takes a binary file as input and compresses it to a bin file that contains the RLE-compressed version. It uses RLE naively without any optimizations or modifications to the algorithm.
#### Usage:
./imxcompressor <file_name>
Example:
./imxcompressor file.bin
It will create another file that starts with cmprsssd_, which will be the compressed version of your binary file.

## Contributing
Feel free to fork this repository and submit pull requests. Any contributions that improve the projects or add new ones are welcome!

## License
This project is licensed under the MIT License.
