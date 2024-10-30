# RLE binary file compressor

This C program takes binary file as an input and it will compress it to a bin file that contains the RLE-compressed version.

This compressor just uses RLE naively without any optimizations and modifications to the algorithm.

This project allowed me to utilize realloc, file i/o, fseek, and sprintf.

## Usage

Run this command: 

    `./imxcompressor <file_name>`

Example

    `./imxcompressor file.bin`

And it will make another file that starts with `cmprsssd_`, that will be the compressed version of your binary file.


