//
//  main.c
//  tinyhttppd
//
//  Created by 김민재 on 11/30/23.
//

#include <stdio.h>
#include <string.h>

int main(int argc, const char * argv[]) {
    if (argc < 2){
        printf("Few arguments!\n");
        return 1;
    }
    unsigned long int hostlength = strlen(argv[1]);
    
    char host[hostlength];
    strcpy(host, argv[1]);
    
    printf("%s\n", host);
    return 0;
}
