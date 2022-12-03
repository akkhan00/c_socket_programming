// Server side Socket Programming in c

#include <stdio.h> // for printf
#include <sys/socket.h> // for socket, bind, listen, recv, send
#include <arpa/inet.h> // for sockaddr_in
#include <unistd.h> // close 

#define PORT 8888

int main(void){
    int server_socket, client_socket;
    
    struct sockaddr_in address; // server address

    // create a server socket 
    server_socket = socket(AF_INET, SOCK_STREAM, 0); // 0 is for protocol

    // add info to address structure
    address.sin_family = AF_INET; // address family of internet
    address.sin_port = htons(PORT);
    address.sin_addr.s_addr = inet_addr("192.168.10.6");

    // Bind to server socket
    bind(server_socket, (struct sockaddr_in *)&address, sizeof(address));

    // listen on server socket
    listen(server_socket, 5); // 5 connections
    // if client connct i will print message on terminal
    printf("Client connected!\n");

    // accept connection
    client_socket = accept(server_socket, (struct sockaddr_in*)&address, sizeof(address));

    // recive message from client socket
    char printBuffer[1024]; // buffer to print on termainl
    recv(client_socket, printBuffer, sizeof(printBuffer), 0);
    // print the recived message
    printf("Reviced Msg: %s\n", printBuffer);

    // send message from server to client socket
    char sendBuffer[1024] = "Hello from Server";
    send(client_socket, sendBuffer, sizeof(sendBuffer), 0);

    close(client_socket);
    close(server_socket);

    return 0;
}
