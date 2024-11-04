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
        htons(8080),
        INADDR_ANY
    };
    int imxs = socket(AF_INET, SOCK_STREAM, 0);
    bind(imxs, (struct sockaddr *) &imxaddr, sizeof(imxaddr));

    listen(imxs, 10); //10 connections can connect

    int client_fd = accept(imxs, NULL, NULL);

    char buffer[256] = {0};
    recv(client_fd, buffer, 256, 0);

    // so this is what it looks when a client sends a request to the socket type server.
    // For GET requests...
    // GET /filename.html 
    char* pFile = buffer + 5;
    *strchr(pFile, ' ') =  0;
    int imxOpenedFile = open(pFile, O_RDONLY);

    sendfile(client_fd, imxOpenedFile, NULL, 256);
    close(imxOpenedFile);
    close(client_fd);
    close(imxs);




    return 0;
}