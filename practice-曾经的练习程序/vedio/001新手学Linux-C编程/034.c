#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>

int main(int argc, char **argv)
{
	mode_t mode = 0750;
	int status;
	if(argc != 2){
		printf("arguement error\n");
		exit(1);
	}
	status = mkfifo(argv[1], mode);
	if(status < 0){
		perror("mkfifo error");
		exit(1);
	}else{
		printf("FIFO create success\n");
	}
	return 0;
}
