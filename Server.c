// Server side Socket Programming in c

#include <stdio.h>      // for printf
#include <sys/socket.h> // for socket, bind, listen, recv, send
#include <arpa/inet.h>  // for sockaddr_in, inet_addr
#include <string.h>     // for compare two string
#include <unistd.h>     // for close
#include "colortext.h"  // to add color to print statement

#define PORT 8877

int main(void)
{
    int server_socket, client_socket;

    struct sockaddr_in address; // server address

    // create a server socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0); // 0 is for protocol

    // add info to address structure
    address.sin_family = AF_INET;                     // address family of internet
    address.sin_port = htons(PORT);                   // port number
    address.sin_addr.s_addr = inet_addr("127.0.0.1"); // you can put your own ip

    // Bind to server socket
    bind(server_socket, (const struct sockaddr *)&address, sizeof(address));

    // listen on server socket
    listen(server_socket, 5); // 5 connections
    printf(Mango "Server listening on port %d\n", PORT);

    // accept connection
    client_socket = accept(server_socket, NULL, NULL);
    // if client connct i will print message on terminal
    printf(Green "Client connected!\n" Rest);

    // use while true loop to connect for long time
    while (1)
    {
        // send message from server to client socket
        char sendBuffer[1024];
        printf(Yellow "Enter Message: " Rest);
        fgets(sendBuffer, 1024, stdin);
        send(client_socket, sendBuffer, sizeof(sendBuffer), 0);
        // check if the command equal to exit then close the porgram
        if (strcmp(sendBuffer, "exit\n\0") == 0)
        {
            printf(Red "Exiting Program!\n" Rest);
            close(server_socket);
            break;
        }

        // recive message from client socket
        char printBuffer[1024]; // buffer to print on termainl
        recv(client_socket, printBuffer, sizeof(printBuffer), 0);
        // print the recived message
        printf(Blue "Reviced Msg: " Rest "%s\n", printBuffer);
    }

    return 0;
}
