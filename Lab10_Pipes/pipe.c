#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>

int main(){
	char parent[] = "Parent: Hello Child";
	char child[] = "Child: Hello Parent";
	
	int fd1[2],fd2[2];
	pid_t p;

	if (pipe(fd1) == -1){
		fprintf(stderr, "Pipe Failed");
		return 1;
	}
	
	if (pipe(fd2) == -1){
		fprintf(stderr, "Pipe Failed");
		return 1;
	}
	
	p = fork();
	
	if (p < 0){
		fprintf(stderr,"fork failed");	
	}
	
	else if (p > 0){

		char str1[100];
		close(fd1[0]); //close reading end of parent process
		write(fd1[1], parent, strlen(parent)+1); //parent writing
		close(fd1[1]);
		
		wait(NULL);
		close(fd2[1]); //close writing end of child process
		read(fd2[0], str1, 100); //child reading
		printf("%s\n",str1);
	}
	
	else {
		char str2[100];

		close(fd1[1]); //close writing end of parent process
		read(fd1[0], str2, 100); //parent reading
		close(fd1[0]);
		printf("%s\n",str2);

		close(fd2[0]); //close reading end of child process
		write(fd2[1], child, strlen(child)+1); //child writing
		close(fd2[1]);
		
		
	}
	
}
