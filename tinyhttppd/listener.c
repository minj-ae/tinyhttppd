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
    int ret = 0;
    struct sockaddr_in server_socket;

    // pid_t pid = fork(); //process id variable type, process copy

    int server = socket(AF_INET, SOCK_STREAM, 0); //create server socket

    if (server == -1) { perror("server error"); return -1; } //create error handle

    memset(&server_socket, 0, sizeof(struct sockaddr_in));
    server_socket.sin_family      = AF_INET;
    server_socket.sin_port        = htons(port);
    server_socket.sin_addr.s_addr = htonl(host);

    ret = bind(server, (struct sockaddr *)&server_socket, sizeof(struct sockaddr_in)); // socket bind
    if (ret == -1) { perror("bind error"); return -1; }

    ret = listen(server, max); // socket listen
    if (ret == -1) { perror("socket listen error"); return -1; }

    printf("success\n");
    return 0;
}