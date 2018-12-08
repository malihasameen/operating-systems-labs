#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h> 
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>

void search(char *argv[]){
    int fd,r,j=0;
    char temp,line[100];
    if((fd=open(argv[2],O_RDONLY)) != -1) {
        while((r=read(fd,&temp,sizeof(char)))!= 0) {
            if(temp!='\n') {
                line[j]=temp;
                j++;
            }

            else {
		line[j]='\0';
                if(strstr(line,argv[1])!=NULL){
                    printf("%s\n",line);
		}

                memset(line,0,sizeof(line));
                j=0;
            }

        }
    }   
}

int main(int argc,char *argv[]){
    struct stat stt;

    if (argc != 3) {
		printf("Usage: %s word file.txt\n",argv[0]);
		return 1;
    }

    if(stat(argv[2],&stt)==0){
		search(argv);
    }
    else {
        perror("stat()");
        exit(1);
    }
}

