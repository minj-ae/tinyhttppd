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

int handle(char *message){
    printf("%s\n", message);
    return 0;
}