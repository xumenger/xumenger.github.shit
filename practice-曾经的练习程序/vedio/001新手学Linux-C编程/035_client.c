#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<errno.h>
#include<fcntl.h>
#define BUFSIZE 256
int main(int argc, char **argv)
{
	int fd;
	char buf[BUFSIZE];
	if(argc != 2){
		printf("arguements error\n");
		exit(1);
	}
	fd = open(argv[1], O_RDONLY);
	if(fd < 0){
		perror("open error");
		exit(1);
	}
	printf("Client:\n");
	read(fd, buf, sizeof(buf));
	printf("Received message: %s", buf);
	return 0;
}
