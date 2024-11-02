#ifndef IMXSHELL
#define IMXSHELL
#include <dirent.h>


// since we print everything needed, these functions tend to have 
// no return value, implementation functions do! like helpers
// we also need to pass the params, to the commands so i put char*
// TYPE DEFINITIONS
typedef void (*CommandFunction)(size_t, char**);

struct Command{
    char* alias;
    CommandFunction cmdFnc;
};

typedef struct Command Command;


// SHELL FUNCTION DECLARATIONS
// prints error for arg size mismatch
void print_argument_size_mismatch(size_t argc, size_t expected);

// Lists directory files and subdirectories given `path`
// if `path` is null, it is the local dir by default
void cmd_list_directory(size_t argc, char** argv);

// FUNCTION DEFINITIONS
void cmd_list_directory(size_t argc, char** argv){
    if(argc > 1){
        print_argument_size_mismatch(argc, 1);
        return;
    }
    char* path;
    if(argc == 0){
        path = malloc(sizeof(char) * 3);
        path  = "./";
    }else{
        path = argv[0];
    }

    DIR* dir = opendir(path);
    struct dirent* currrent_fs_object;
    while(currrent_fs_object = readdir(dir)){
        printf("%s ", currrent_fs_object->d_name);
    };
    printf("\n");

}

void print_argument_size_mismatch(size_t argc, size_t expected){
    if(argc != expected){
        printf("[Error]:This command expects %d arguments, got %d.\n", expected, argc);
        return;
    }
}
#endif