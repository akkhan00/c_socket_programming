#include <stdio.h>      // for printf
#include <sys/socket.h> // for socket, send, recv, connect
#include <arpa/inet.h>  // for sockaddr_in
#include <string.h>     // for string comparison
#include <unistd.h>     // close the connection

#define PORT 8877 // same port as in server Or server port which you want to connect

int main(void)
{
    // create server_socket
    int server_socket;

    // create socket address
    struct sockaddr_in server_address;

    // create a socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0);

    // add server info to struct server_address
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(PORT);                   // The htons() function translates a short integer from host byte order to network byte order
    server_address.sin_addr.s_addr = inet_addr("127.0.0.1"); // The inet_addr function converts a string containing an IPv4 dotted-decimal address into a proper address for the IN_ADDR structure

    // connect to server
    connect(server_socket, (const struct sockaddr *)&server_address, sizeof(server_address));

    while (1)
    {
        // recive data from server
        char reciveBuffer[1024];
        recv(server_socket, reciveBuffer, sizeof(reciveBuffer), 0);
        printf("Recived: %s\n", reciveBuffer);
        // check if the command is equal to exit then close the connection
        if (strcmp(reciveBuffer, "exit\n\0") == 0)
        {
            printf("Exiting Program!\n");
            close(server_socket);
            break;
        }

        // send data to server
        char sendBuffer[1024];
        printf("Enter message: ");
        fgets(sendBuffer, 1024, stdin);
        send(server_socket, sendBuffer, sizeof(sendBuffer), 0);
    }
    // close socket

    return 0;
}