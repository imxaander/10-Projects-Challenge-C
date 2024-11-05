#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <fcntl.h>
#include <sys/sendfile.h>
#include <unistd.h>

int main(){
    struct sockaddr_in imxaddr = {
        AF_INET,
        htons(3565),
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
        printf("Binding socket success! Port: %x\n", imxaddr.sin_port);
    }

    printf("Starting to listen to socket connections..\n");
    if(listen(imxs, 10) == -1){ //10 connections can connect
        perror("Listen failed.");
        return 1;
    }else{
        printf("Success!. Listening to socket connections....\n");
    }

    int client_fd;
    printf("Starting to Accept socket connections..\n");
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
        return 1;
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
        close(client_fd);
        close(imxs);
        perror("Open file failed.");
        return 1;
    }else{
        printf("Successfully opened file from request!\n");
    };

    printf("Sending file back to the client ...\n");

    char* request_header_success = "HTTP/1.1 200 OK\r\nServer: IMXAANDER\r\nContent-Type: text/html\r\n\r\nFile Found.\r\n";
    // strcat()
    if(sendfile(client_fd, imxOpenedFile, NULL, 25) == -1){
        perror("Sending file failed.");
        return 1;
    }else{
        printf("File Sent to the client...\n");
    }
    
    printf("Exiting.. \n");
    close(imxOpenedFile);
    close(client_fd);
    close(imxs);

    return 0;
}