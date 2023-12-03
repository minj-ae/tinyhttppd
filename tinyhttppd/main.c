//
//  main.c
//  tinyhttppd
//
//  Created by 김민재 on 11/30/23.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "server.h"

int main(int argc, const char * argv[]) {
    if (argc < 4){ // Argument count check
        printf("Usage: %s [IP] [PORT] [QUEUE-MAXIMUM]\n", argv[0]);
        return 1;
    }
    int host = addressc(argv[1]);
    int port = portc(argv[2]);
    int max = var(argv[3]);

    int ret = start(host, port, max);
    return ret;
}
