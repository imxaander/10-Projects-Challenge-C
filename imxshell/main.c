#include <malloc.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

// MY OWN LIBRARIES <3
#include "mychelper.h"

// MACROS AND CONSTANTS
#define EXIT_COMMAND "exit"
#define INPUT_PREFIX "xander>"
#define INPUT_MAX_SIZE 256

// FUNCTION DECLARATIONS
void welcome_message();

int main(int argc, char** argv){
    welcome_message();

    char* input;
    do{
        printf("\n%s ", INPUT_PREFIX);
        input = get_line();
    }while(strcmp(input, EXIT_COMMAND));

    // printf("input : %s, ", input);
    // printf("size of input: %d", getStringLength(input));
    return 0;
}

void welcome_message(void){
    printf(" _____ ___  _____   __ _____  _   _  _____  _      _     \n");
    printf("|_   _||  \\/  |\\ \\ / //  ___|| | | ||  ___|| |    | |    \n");
    printf("  | |  | .  . | \\ V / \\ `--. | |_| || |__  | |    | |    \n");
    printf("  | |  | |\\/| | /   \\  `--. \\|  _  ||  __| | |    | |    \n");
    printf(" _| |_ | |  | |/ /^\\ \\/\\__/ /| | | || |___ | |____| |____\n");
    printf(" \\___/ \\_|  |_/\\/   \\/\\____/ \\_| |_/\\____/ \\_____/\\_____/\n");
    printf("Shell By: imxaander\t\tVersion 1.0\n");
    printf("                                                         \n");
}
