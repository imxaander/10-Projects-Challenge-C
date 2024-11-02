#include <malloc.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdlib.h>
#include <signal.h>
#include <wait.h>

// MY OWN LIBRARIES <3
#include "mychelper.h"

// MACROS AND CONSTANTS
#define EXIT_COMMAND "exit"
#define INPUT_PREFIX "xander>"
#define INPUT_MAX_SIZE 256
#define BINARY_DIR "/bin/"

// CONSTANTS

// FUNCTION DECLARATIONS
void welcome_message();

int main(int argc, char** argv){
    welcome_message();
    char* input;
    do{
        printf("\n%s ", INPUT_PREFIX);
        input = get_line();

        //check if blank, continue if yes
        if(input == NULL) continue;

        // validate command if it exists in your system
        
        char* input_token = strtok(input, " ");

        // parse arguments from input_token
        char* arguments = strtok(NULL, " ");
        while(arguments != NULL){
            printf("%s\n", arguments);
            arguments = strtok(NULL, " ");
        }
        char* binpath = (char*) malloc((getStringLength(input_token) + getStringLength(BINARY_DIR) - 1) * sizeof(char));
        strcpy(binpath, BINARY_DIR);
        char* fullbinpath = strcat(binpath, input_token);
        // printf("%s\n", fullbinpath);
        FILE* tmp;
        if(tmp = fopen(fullbinpath, "r")){
            fclose(tmp);
            free(input_token);
            // valid unix system command..
            // printf("child process started...\n");
            __pid_t unix_command_process = fork();
            if(unix_command_process == 0){
                execl(fullbinpath, "Hello World!", NULL);
                perror("execl"); 
                exit(EXIT_FAILURE);
            }else{
                int status;
                waitpid(unix_command_process, &status, 0);
                // printf("child process exited, pid: %d", getpid());
                free(binpath);
                continue;
            }
        }
        printf("Not a valid command on your system.");
    }while(1);

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
}

