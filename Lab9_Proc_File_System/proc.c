#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h> 
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>

void info(char* path, char* word){
	int fd,r,j=0;
    	char temp,line[512];
	if((fd=open(path,O_RDONLY)) != -1) {
        	while((r=read(fd,&temp,sizeof(char)))!= 0){
			if(temp!='\n') {
                		line[j]=temp;
                		j++;
            		}
			else {
				line[j]='\0';
                		if(strstr(line,word)!=NULL){
                    			printf("%s\n",line);
					return;
				}

                		memset(line,0,sizeof(line));
                		j=0;
           		}
		}
    	}
	close(fd);
}

void cpu(char* file){
	size_t fd,r,j=0; char*  arr[12];
	char temp,line[512];  
    	if((fd=open(file,O_RDONLY)) != -1){
     		if(j<1){
	  		while(r=read(fd,&temp,sizeof(char))){
	  			if(temp!='\n'){
                			line[j]=temp;
                			j++;
            			}
            			else{
					line[j]='\0';            
                			j=0;
					char *token;
					char*rest = line;
					int i=0;
	      				/* walk through other tokens */
		   			while( token= strtok_r(rest," ", &rest)){
 						arr[i]=token;
						i++;
		      			} 
		        		printf( "User Mode Time\t:%s\n", arr[1] ); 
					printf( "Kernel Mode Time:%s\n", arr[3] ); 
					printf( "Idle Time\t:%s\n", arr[4] ); 
		     
					memset(line,0,sizeof(line));
					return;
            			} 

        		}
        	}
    	}    
 	close(fd);
}

int main()
{
	printf("Model_Name: ");
	info("/proc/cpuinfo","model name");

	printf("Vendor_ID: ");
	info("/proc/cpuinfo","vendor_id");

	printf("Kernel: ");
	info("/proc/version_signature","Ubuntu");

	printf("Memory Configured: ");
	info("/proc/meminfo","MemTotal");

	printf("Memory Available: ");
	info("/proc/meminfo","MemFree");

	printf("Boot Time: ");
	info("/proc/uptime","");
	
	cpu("/proc/stat");
	return 0;
}

