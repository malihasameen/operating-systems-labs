#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int numbers[100];
int global_sum = 0;
int compute_sum[4] = {0};

void createArray(){
	for (int i=0;i<100;i++){
		numbers[i] = (rand() % 10) + 1;
	}
}

void *sum(void* index){
	int* Index = (int*)index;
	for(int i=Index[0];i<=Index[1];i++){
		compute_sum[Index[2]] += numbers[i];
	}
}

void main(){
	pthread_t t1,t2,t3,t4;
	clock_t start;
	int index1[] = {0,24,0};
	int index2[] = {25,49,1};
	int index3[] = {50,74,2};
	int index4[] = {75,99,3};

	createArray();
	start=clock();

	int iret1 = pthread_create( &t1, NULL, &sum,(void*)index1);
	if(iret1){
	         fprintf(stderr,"Error - pthread_create() return code: %d\n",iret1);
	         exit(EXIT_FAILURE);
	}
	
	int iret2 = pthread_create( &t2, NULL, &sum,(void*)index2);
	if(iret2){
	         fprintf(stderr,"Error - pthread_create() return code: %d\n",iret2);
	         exit(EXIT_FAILURE);
	}

	int iret3 = pthread_create( &t3, NULL, &sum,(void*)index3);
	if(iret3){
	         fprintf(stderr,"Error - pthread_create() return code: %d\n",iret3);
	         exit(EXIT_FAILURE);
	}

	int iret4 = pthread_create( &t4, NULL, &sum,(void*)index4);
	if(iret4){
	         fprintf(stderr,"Error - pthread_create() return code: %d\n",iret4);
	         exit(EXIT_FAILURE);
	}
	
	pthread_join(t1,NULL);
	pthread_join(t2,NULL);
	pthread_join(t3,NULL);
	pthread_join(t4,NULL);
	
	for (int i=0; i<4; i++){
		global_sum += compute_sum[i];
	}
	
	double time_taken = ((double)(clock()-start))/CLOCKS_PER_SEC;

	printf("Thread1 returns: %d\n",iret1);
	printf("Thread2 returns: %d\n",iret2);
	printf("Thread3 returns: %d\n",iret3);
	printf("Thread4 returns: %d\n",iret4);
	printf("Total Sum: %d\n",global_sum);
	printf("Time taken is: %f seconds \n", time_taken);			
} 
