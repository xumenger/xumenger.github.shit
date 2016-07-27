#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/sem.h>

int main(){
	int semid;
	key_t key;
	key = ftok("/home/perfect", "a");
	if(key < 0){
		perror("ftok error");
		exit(1);
	}
	semid = semget(key, 1,IPC_CREAT | 0666);
	if(semid < 0){
		perror("semget error");
		exit(1);
	}
	printf("Done");
	return 0;
}
