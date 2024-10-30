#include "strimx.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char* argv[]){
    // filename arg
    char* fnarg = argv[1];
    // we create a place for the compressed data
    char* compressed_data = (char*) malloc(0);
    // printf("%s", argv[1]);
    
    // run checks for null params
    if(argc != 2) {
        printf("[Error]: Incorrect file name parameter.\n\tUsage:\n\timxcompress <file_name>");

        // error code 1 means no parameter
        return 1;
    }

    // check if file exists
    FILE* fexists = fopen(fnarg, "r");
    if(fexists == NULL){
        printf("[Error]: File does not exist.\n\tNote:\n\tfile with the argument <file_name> should exist in the same folder.");

        // error code 2 means no file exists that has the file name 
        return 2;
    }


    char* filename = "file.bin";
    // reads file with the file name `filename` in the local folder and put reference in the file stream `fb`
    FILE* fb = fopen(filename, "rb");

    unsigned int file_size; 

    fseek(fb, 0, SEEK_END);
    file_size = ftell(fb);
    fseek(fb, 0, SEEK_SET); //SEEK_SET goes to the goes to the beginning of the file..


    // now we can malloc and put it inside a character array 
    char* data = (char*) malloc((file_size + 1) * sizeof(char));
    fread(data, sizeof(char), file_size, fb);

    // now we have the data, we can now run it through RLE algorithm...
    unsigned int i, j;
    for(i = 0; *(data + i) != '\0'; i = j){
        char curr_char = *(data + i);
        unsigned int count = 0;
        for(j = i; *(data + j) == curr_char; j++){
            // printf("Compare %c, %c", curr_char, *(data + j));
            count++;
        }

        // we need to append the count and current character inside the compressed data variable
        // considering that we need to reallocate memory for us to be able to optimize the memory usage.

        char* b = realloc(compressed_data, (getStringLength(compressed_data) + 2) * sizeof(char));

        // set the pointer to char of compressed data to the reallocated memory pointer
        compressed_data = b;

        // write the formatted string to the reallocated memory
        sprintf(compressed_data, "%s%d%c", compressed_data, count, curr_char);


        // printf("Size of compressed data : %d\n", getStringLength(compressed_data));

        // printf("%s%d%c", compressed_data, curr_char);q
        // printf("Compare %c, %c", curr_char, *(data + j));
    }


    // printf("\nString: %s , Size: %d\n", data , file_size);
    // printf("Compressed: %s, size: %d", compressed_data, getStringLength(compressed_data));

    FILE* cfb = fopen(concatString("cmprsssd_", filename), "wb");
    fwrite(compressed_data, sizeof(char), (getStringLength(compressed_data) - 1) * sizeof(char), cfb);
    
    return 0;
}