//
//  listener.c
//  tinyhttppd
//
//  Created by 김민재 on 12/03/23.
//

#include "server.h"
#include <sys/socket.h>
#include <memory.h>
#include <netinet/in.h>
#include <netinet/ip.h> 
#include <unistd.h>
#include <stdio.h>

int start(int host, int port, int max){
    int message_size;
    struct sockaddr_in server_socket;
    struct sockaddr_in client_socket;
    socklen_t client_address_size;
    int hflag;

    char message[48000];

    // pid_t pid = fork(); //process id variable type, process copy

    int server = socket(AF_INET, SOCK_STREAM, 0); //create server socket

    if (server == -1) { perror("server error"); return -1; } //create error handle

    memset(&server_socket, 0, sizeof(struct sockaddr_in));
    server_socket.sin_family      = AF_INET;
    server_socket.sin_port        = htons(port);
    server_socket.sin_addr.s_addr = htonl(host);

     // socket bind
    if (bind(server, (struct sockaddr *)&server_socket, sizeof(struct sockaddr_in)) == -1) { perror("bind error"); return -1; }

    if (listen(server, max) == -1) { perror("socket listen error"); return -1; }
    
    client_address_size = sizeof(client_socket);

    while(1){
        int client = accept(server, (struct sockaddr*)&client_socket, &client_address_size);
        if (client == -1) { perror("client accept error"); close(client); continue;}
        pid_t pid = fork(); //process id variable type, process copy
        if (pid == -1) {close(client);}
        if (pid == 0) {
            memset(message, '\0', 48000);
            message_size = recv(client, message, sizeof(message)-1, MSG_PEEK);
            if (message_size == -1) { perror("read error"); printf("1\n"); continue;}
            hflag = filter(message);
            if(hflag == -1){
                handle(message);
            }
        }
        else {
            continue;
        }
	}

    close(server);
    return 0;
}