#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// argc = argument count
// argv = argument values
float main(int argc, char* argv[]){
    
    float fN = atoi(argv[1]);
    float sN = atoi(argv[3]);
    char op = argv[2][0];
    float result;

    switch (op)
    {
    case '+':
        result = fN + sN;
        break;

    case '-':
        result = fN - sN;
        break;

    case '*':
        result = fN * sN;
        break;
    
    case '/':
        result = fN / sN;
        break;
    default:
        // error here
        printf("Encountered and error.");
        return 1;
    }
    printf("= %f\n", result);
    return 0;
}