#ifndef IMXSHELL
#define IMXSHELL
#include <stdio.h>

// since we print everything needed, these functions tend to have 
// no return value, implementation functions do! like helpers
// we also need to pass the params, to the commands so i put char*
// TYPE DEFINITIONS
typedef void (*CommandFunction)(int, char**);

struct Command{
    char* alias;
    CommandFunction cmdFnc;
};

typedef struct Command Command;

// SHELL FUNCTION DECLARATIONS

// Lists directory files and subdirectories given `path`
// if `path` is null, it is the local dir by default
void cmd_list_directory(int, char** argv);


// FUNCTION DEFINITIONS
void cmd_list_directory(int, char** argv){

}

#endif