#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <fcntl.h>
#include <sys/sendfile.h>
#include <unistd.h>
#include <sys/stat.h>
#include <stdlib.h>

#define MAX_SIZE 4096
int main(int argc, char* argv[]){
    if(argc < 2){
        printf("No port provided or invalid argument.");
        return 0;
    };
    in_port_t port = atoi(argv[1]);

    struct sockaddr_in imxaddr = {
        AF_INET,
        htons(port),
        INADDR_ANY
    };

    int imxs;
    
    printf("Starting Socket...\n");
    if((imxs = socket(AF_INET, SOCK_STREAM, 0)) == -1){
        perror("Socket is not created.");
        return 1;
    }else{
        printf("Socket successfully created\n");
    }

    printf("Binding socket configurations to socket..\n");
    if(bind(imxs, (struct sockaddr *) &imxaddr, sizeof(imxaddr)) == -1){
        perror("Bind failed.");
        return 1;
    }else{
        printf("Binding socket success! Port: %d\n", port);
    }

    printf("Starting to listen to socket connections..\n");
    if(listen(imxs, 10) == -1){ //10 connections can connect
        perror("Listen failed.");
        return 1;
    }else{
        printf("Success!. Listening to socket connections....\n");
    }

    while(1){
        printf("===================================\n");
        printf("Starting to Accept socket connections..\n");
        int client_fd;
        if((client_fd = accept(imxs, NULL, NULL)) == -1){
            perror("Accept connection failed.");
            return 1;
        }else{
            printf("Accepted a connection\n");
        };

        char buffer[256] = {0};
        printf("Starting to Recieve socket information..\n");
        if(recv(client_fd, buffer, 255, 0) == -1){
            perror("Recieve connection failed.");
            continue;
        }else{
            printf("Socket connection information recieved.\n");
        };

        // so this is what it looks when a client sends a request to the socket type server.
        // For GET requests...
        // GET /filename.html 
        char* pFile = buffer + 5;
        *strchr(pFile, ' ') =  0;

        printf("Recieved request for file name: %s\n", pFile);

        
        int imxOpenedFile;
        printf("Opening file from request..\n");
        if((imxOpenedFile = open(pFile, O_RDONLY)) == -1){
            char* open_file_failed_msg = "HTTP/1.1 404 Not Found\r\nServer: IMXAANDER\r\nContent-Type: text/plain\r\n\r\nFile not found.";
            send(client_fd, open_file_failed_msg, strlen(open_file_failed_msg), 0);
            close(imxOpenedFile);
            close(client_fd);
            perror("Open file failed.");
            continue;
        }else{
            printf("Successfully opened file from request!\n");
        };

        printf("Sending file back to the client ...\n");


        struct stat file_stat;
        fstat(imxOpenedFile, &file_stat);
        size_t file_size = file_stat.st_size;

        char* request_header = "HTTP/1.1 200 OK\r\nServer: IMXAANDER\r\nContent-Type: text/html\r\n\r\n";
        send(client_fd, request_header, strlen(request_header), 0);
        
        
        off_t offset = 0;
        while(file_size > 0){
            ssize_t sentbytes = sendfile(client_fd, imxOpenedFile, &offset, file_size);
                if (sentbytes == -1) {
                perror("Sending file failed");
                close(imxOpenedFile);
                close(client_fd);
                continue;
            }

            file_size -= sentbytes;

        }
        printf("Request Done.. \n");
        close(imxOpenedFile);
        close(client_fd);
    }
    close(imxs);

    return 0;
}