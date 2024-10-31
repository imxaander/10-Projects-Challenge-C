#include <string.h>
#include <stdio.h>

int main(int argc, char** argv)
{
    char* arguments =  argv[1];
    
    while(arguments != NULL){
        printf("%s\n", arguments);  
        arguments = strtok(arguments, "-");
    }


    return 0;
}