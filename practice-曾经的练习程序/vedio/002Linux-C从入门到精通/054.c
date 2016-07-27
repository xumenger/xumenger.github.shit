#include<stdlib.h>
#include<stdio.h>
#include<sys/shm.h>
#include<sys/ipc.h>
#include<unistd.h>

typedef struct
{
	char name[4];
	int age;
}people;

int main(int argc, char **argv)
{
	int shm_id, i;
	char temp;
	people *p_map;
	if(argc != 2){
		printf("fuck\n");
		return 0;
	}
	shm_id = atoi(argv[1]);
	p_map = (people*)shmat(shm_id, NULL, 0);
	temp = 'a';
	for(i=0; i<10; i++){
		temp+=1;
		memcpy((*(p_map+i)).name, &temp, 1);
		(*(p_map+i)).age = 20+i;
	}
	if(shmdt(p_map)==-1)
		perror("fuck, fuck");
	return 0;
}
