//
//  util.c
//  tinyhttppd
//
//  Created by 김민재 on 12/03/23.
//

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <errno.h>
#include <string.h>
#include <sys/_types/_socklen_t.h>

union
{
    unsigned int integer;
    unsigned char byte[4];
} itoch;

int stohi(const char *ip){
	char c;
	c = *ip;
	unsigned int integer;
	int val;
	int i,j=0;
	for (j=0;j<4;j++) {
		if (!isdigit(c)){ 
			return (0);
		}
		val=0;
		for (i=0;i<3;i++) {
			if (isdigit(c)) {
				val = (val * 10) + (c - '0');
				c = *++ip;
			} else
				break;
		}
		if(val<0 || val>255){
			return (0);	
		}	
		if (c == '.') {
			integer=(integer<<8) | val;
			c = *++ip;
		} 
		else if(j==3 && c == '\0'){
			integer=(integer<<8) | val;
			break;
		}
			
	}
	if(c != '\0'){
		return (0);	
	}
	return (integer);
}

int addressc(const char * address){
	if (strlen(address) > 15) {
        return -1;
    }
    return stohi(address);
}

int portc(const char * port){
	char* p;
    errno = 0;
	long strtolport = strtol(port, &p, 10); // argc[2] convert to long
	if (*p != '\0' || errno != 0) {
        return -1; // In main(), returning non-zero means failure
    }
	if (strtolport < 1 || strtolport > 65535){
		return -1;
	}
	else {
		return (int)strtolport;
	}
}

int var(const char * max){
	return atoi(max);
}