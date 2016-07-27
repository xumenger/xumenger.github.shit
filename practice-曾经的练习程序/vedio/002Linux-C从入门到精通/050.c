#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<fcntl.h>

#define BUFES PIPE_BUF

int main(void)
{
	int fd;
	int len;
	char buf[BUFES];
	mode_t mode = 0666;
	if((fd=open("fifo1", O_RDONLY))<0){
		printf("open error\n");
		exit(1);
	}
	while((len=read(fd, buf, BUFES))>0)
		printf("Read : %s\n", buf);
	close(fd);
	exit(1);
}
