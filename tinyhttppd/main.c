//
//  main.c
//  tinyhttppd
//
//  Created by 김민재 on 11/30/23.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>
#include <errno.h>

int main(int argc, const char * argv[]) {
    if (argc < 2){ // Argument count check
        printf("Few arguments!\n");
        return 1;
    }

    char* p;
    errno = 0;
    unsigned long int hostlength = strlen(argv[1]);
    if (hostlength > 15){ // basic ip valid check
        return 1;
    } 
    // int port = (int)*argv[2];
    long strtolport = strtol(argv[2], &p, 10); // argc[2] convert to long
    if (*p != '\0' || errno != 0) {
        return 1; // In main(), returning non-zero means failure
    }
    char host[hostlength];
    strcpy(host, argv[1]);
    
    if (strtolport < INT_MIN || strtolport > INT_MAX) {
        return 1;
    }

    int port = strtolport;


    printf("%s\n", host);
    printf("%d\n", port);
    return 0;
}
