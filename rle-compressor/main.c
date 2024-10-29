#include "RLECompress.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
    // writes file.bin in the local folder and put reference in the file stream `fb`
    FILE *fb = fopen("file.bin", "rb");

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
        printf("%d%c", count, curr_char);
        // printf("Compare %c, %c", curr_char, *(data + j));
    }
    printf("\nString: %s , Size: %d", data , file_size);

}