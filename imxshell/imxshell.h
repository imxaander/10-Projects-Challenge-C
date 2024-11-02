#ifndef IMXSHELL
#define IMXSHELL
#define MAX_BUFFER 256


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
void cmd_clear_screen(size_t argc, char** argv);
void cmd_change_directory(size_t argc, char** argv);
void cmd_get_working_directory(size_t argc, char** argv);
void cmd_test(size_t argc, char** argv);


void execute_system_command(size_t command_id, char* exec_path, char** args);


// FUNCTION DEFINITIONS

// clears the terminal screen
void cmd_clear_screen(size_t argc, char** argv){
    printf("\033[H\033[J");
};

// lists directory given argc argv that treats it like path
void cmd_list_directory(size_t argc, char** argv){
    if(argc > 2){
        print_argument_size_mismatch(argc, 1);
        return;
    }
    char* path;
    if(argc == 1){
        path = malloc(sizeof(char) * 3);
        strcpy(path, "./");
    }else{
        path = argv[1];
    }

    DIR* dir = opendir(path);

    if (!dir) {
    perror("Error opening directory");
        return;
    }

    struct dirent* currrent_fs_object;
    while(currrent_fs_object = readdir(dir)){
        printf("%s ", currrent_fs_object->d_name);
    };
    printf("\n");
}

// change the current working directory
void cmd_change_directory(size_t argc, char** argv){
    if(argc > 2){
        print_argument_size_mismatch(argc, 1);
        return;
    }
    char* path;
    if(argc == 1){
        path = malloc(sizeof(char) * 3);
        strcpy(path, "./");
    }else{
        path = argv[1];
    }
    if(chdir(path) != 0){
        perror("Error changing directory");
    };
};

void cmd_get_working_directory(size_t argc, char** argv){
    char path[MAX_BUFFER];

    if (getcwd(path, MAX_BUFFER) == NULL){
        perror("Cannot get the current working directory.");
        return;
    }
    printf("%s\n", path);
};
void cmd_test(size_t argc, char** argv){

}

void print_argument_size_mismatch(size_t argc, size_t expected){
    if(argc != expected){
        printf("[Error]:This command expects %d arguments, got %d.\n", expected, argc);
        return;
    }
}

// executes the unix system command 
void execute_system_command(size_t command_id, char* exec_path, char** args){
    printf("child process started...\n");
    __pid_t unix_command_process = fork();
    if(unix_command_process == 0){
        execv(exec_path,  args);
        perror("execl"); 
        exit(EXIT_FAILURE);
    }else{
        int status;
        waitpid(unix_command_process, &status, 0);
        printf("child process exited, pid: %d\n", getpid());
    }
}


#endif