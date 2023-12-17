//
//  server.h
//  tinyhttppd
//
//  Created by 김민재 on 12/03/23.
//

#ifndef SERVER_H
#define SERVER_H

int start(int host, int port, int max);
int stohi(const char *ip);
int addressc(const char * address);
int portc(const char * port);
int var(const char * max);
int filter(char *message);
int handle(char *message);

#endif