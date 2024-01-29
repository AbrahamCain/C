#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>

#define PORT 8443

int main(int argc, char *argv[]){

        const char* response = "Hello. Type 'exit' to close the connection\n";
        const char* response2 = "I got your data\n";

        struct sockaddr_in dest;
        struct sockaddr_in serv;
        int servSock;
        socklen_t sockSize = sizeof(struct sockaddr_in);


        memset(&serv, 0, sizeof(serv));
        serv.sin_family = AF_INET;
        serv.sin_addr.s_addr = htonl(INADDR_ANY);
        serv.sin_port = htons(PORT);

        servSock = socket(AF_INET, SOCK_STREAM, 0);

        bind(servSock, (struct sockaddr *)&serv, sizeof(struct sockaddr));

        listen(servSock, 1);
        int consocket = accept(servSock, (struct sockaddr *)&dest, &sockSize);
        char clientData[1024];


        while(clientData != "exit"){
                char clientData[1024];
                printf("You are receiving a connection from %s - Sending them the message\n", inet_ntoa(dest.sin_addr));
                send(consocket, response, strlen(response), 0);
                recv(consocket, clientData, sizeof(clientData), 0);
                send(consocket, response2, strlen(response2), 0);
                close(consocket);
                printf("closing the socket\n");
                printf("\n%s\n\n", clientData);
                consocket = accept(servSock, (struct sockaddr *)&dest, &sockSize);
        }

        close(servSock);
        printf("Client sent the following:\n\n%s\n", clientData);
        return 0;
}
