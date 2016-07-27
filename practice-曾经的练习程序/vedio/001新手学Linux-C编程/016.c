#include<stdio.h>
#include<stdlib.h>
#include<error.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<sys/types.h>

int main()
{
	int fd;
	fd = open("test", O_CREAT | O_EXCL, 00750);
	if(fd == -1){
		perror("open error");
		exit(1);
	}
	;
	close(fd);

	return 0;
}
