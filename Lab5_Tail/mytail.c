#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h> 
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>

int i = 0;
char buffer[1000];

void printLine(){
	while(i != 0){
		printf("%c",buffer[i]);
		i--;	
	}
	printf("\n");
}

void tail(int fd, int n){
	int r;
	char c;
	int offset = lseek(fd,0,SEEK_END);
	lseek(fd, -2, SEEK_CUR);
	while(offset > 0 && n > 0){
		read(fd, &c, 1);
		if ( c == '\n'){
			i--;
			printLine();
			n--;
		}
		else {
			buffer[i] = c;
			i++;
		}
		lseek(fd, -2, SEEK_CUR);
		offset--;	
	}
	
}


int main(int argc, char *argv[]){
	
	int fd, n;

	if (argc != 3){
		printf("Usage: %s number file.txt",argv[0]);
		return 1;	
	}
	
	if ((fd = open(argv[2],O_RDONLY)) == -1){
		printf("%s cannot be opened in read only mode",argv[2]);
		return 2;
	}
	
	//fd = open(argv[2],O_RDONLY);
	n = atoi(argv[1]);
	tail(fd,n);
}
