#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<errno.h>
#include<stdlib.h>

int main(int argc, char **argv)
{
	mode_t mode = 0666;
	if(argc != 2){
		printf("USEMSG : Create_FIFO\n");
		exit(1);
	}
	if((mkfifo(argv[1], mode))<0){
		perror("failed to mkfifio\n");
		exit(1);
	}
	else{
		printf("success\n");
	}
	return 0;
}
