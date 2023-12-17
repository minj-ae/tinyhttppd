//
//  handler.c
//  tinyhttppd
//
//  Created by 김민재 on 12/03/23.
//

#include "server.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int filter(char *message){

    printf("%s\n", message);
    //find a match with an HTTP message
	//HTTP
	if ((message[0] == 'H') && (message[1] == 'T') && (message[2] == 'T') && (message[3] == 'P')) {
		goto KEEP;
	}
	//GET
	if ((message[0] == 'G') && (message[1] == 'E') && (message[2] == 'T')) {
		goto KEEP;
	}
	//POST
	if ((message[0] == 'P') && (message[1] == 'O') && (message[2] == 'S') && (message[3] == 'T')) {
		goto KEEP;
	}
	//PUT
	if ((message[0] == 'P') && (message[1] == 'U') && (message[2] == 'T')) {
		goto KEEP;
	}
	//DELETE
	if ((message[0] == 'D') && (message[1] == 'E') && (message[2] == 'L') && (message[3] == 'E') && (message[4] == 'T') && (message[5] == 'E')) {
		goto KEEP;
	}
	//HEAD
	if ((message[0] == 'H') && (message[1] == 'E') && (message[2] == 'A') && (message[3] == 'D')) {
		goto KEEP;
	}

    goto DROP;

    KEEP:
    printf("HTTP True\n");
    return -1;
    
    DROP:
    printf("HTTP False\n");
    return 0;
}

int handle(char *message){
    printf("Handled message: %s\n", message);
    return 0;
}