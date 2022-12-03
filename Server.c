// Server side Socket Programming in c

#include <stdio.h> // for printf
#include <sys/socket.h> // for socket, bind, listen, recv, send
#include <arpa/inet.h> // for sockaddr_in

int main(void){
    int server_socket, client_socket;
    
    struct sockaddr_in address; // server address

    // create a server socket 
    server_socket = socket(AF_INET, SOCK_STREAM, 0); // 0 is for protocol
    

    return 0;
}
