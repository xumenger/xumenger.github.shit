#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<errno.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#define BUFSIZE 256

int main(int argc, char **argv)
{
	int status;
	int fd;
	char buf[BUFSIZE];
	if(argc != 2){
		printf("arguements error\n");
		exit(1);
	}
	status = mkfifo(argv[1], 0750);
	if(status < 0){
		perror("mkfifo error");
		exit(1);
	}
	fd = open(argv[1], O_WRONLY);
	if(fd < 0){
		perror("mkfifo error");
		exit(1);
	}
	printf("Server:\n");
	printf("Input the message:");
	fgets(buf, sizeof(buf), stdin);
	write(fd, buf, sizeof(buf));
	printf("Send!\n");
	unlink(argv[1]);

	return 0;
}
