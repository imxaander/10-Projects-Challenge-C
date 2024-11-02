#include <malloc.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

// MY OWN LIBRARIES <3
#include "mychelper.h"
#include "imxshell.h"

// MACROS AND CONSTANTS
#define INPUT_PREFIX "xander>"
#define NCID -1

enum command_ids{
    LIST_DIRECTORY = 0,
    LIST_DIRECTORY2,

};

// COMMANDS LOOKUP TABLE
Command commands_lookup[] = {
    [LIST_DIRECTORY] =  {"ls", cmd_list_directory},
    [LIST_DIRECTORY2] =  {"ls3", cmd_list_directory},
};


// FUNCTION DECLARATIONS
// prints welcome message for the shell
void welcome_message();

// gets the command id from an alias.
// return value >= 0 is the id of the command
// return value -1 means no id for the command
int get_command_id(char* alias);

// gets the command lookup size;
size_t get_commands_lookup_size();

// parse the arguments into array 
char** parse_arguments(char* args, size_t* size);

// executes the command id passed with args
void execute_command(size_t command_id, size_t argc, char** args);

// prints arguments
void print_args(size_t argc, char** argv);


int main(int argc, char** argv){
    welcome_message();
    char* input;
    do{
        printf("%s ", INPUT_PREFIX);
        input = get_line();

        //check if blank, continue if yes
        if(input == NULL) continue;
        size_t arg_string_size = getStringLength(input);

        // gets the first token : command alias
        char input_dup[arg_string_size];
        strcpy(input_dup, input);

        char* input_token = strtok(input_dup, " ");
        int command_id = get_command_id(input_token);
        if(command_id >= 0){
            size_t arg_size;
            char** arg_values = parse_arguments(input, &arg_size);
            // for(size_t i = 0; i < arg_size; i++){
            //     printf("%s\n", *(arg_values + i));
            // }
            execute_command(command_id, arg_size, arg_values);
            // execute programs now
            
            continue;
        }
        printf("Not a valid command on your system.\n");
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

int get_command_id(char* alias){
    size_t i = 0;
    size_t lookup_size = get_commands_lookup_size();
    while(strcmp(commands_lookup[i].alias, alias) != 0){
        if(++i == lookup_size) return NCID; //NO COMMAND ID
    };

    return (int)i;
};

size_t get_commands_lookup_size(){
    size_t size = (size_t) sizeof(commands_lookup) / sizeof(Command);
    return size;
}

char** parse_arguments(char* args, size_t* size){
    char** args_array = (char**) malloc(0);
    char* arg_tokens = strtok(args, " "); //first call gets first word (command alias)
    arg_tokens = strtok(NULL, " ");

    size_t i = 0; //arg pointer counter
    while(arg_tokens != NULL){
        char** tmp_args_array = realloc(args_array, (i + 1) * sizeof(char*));
        args_array = tmp_args_array;
        *(args_array + i) = malloc((getStringLength(arg_tokens) + 1)* sizeof(char));
        strcpy(*(args_array + i), arg_tokens);
        arg_tokens = strtok(NULL, " ");
        i++;
    }
    *(size) = (int)i;
    return args_array;
}

void execute_command(size_t command_id, size_t argc, char** args){
    commands_lookup[command_id].cmdFnc(argc, args);
}

void print_args(size_t argc, char** argv){
    for(size_t i = 0; i < argc; i++){
        printf("%s\n", *(argv + i));
    }
}

