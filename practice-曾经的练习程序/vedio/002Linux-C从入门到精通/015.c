#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define FILENAME "./test"
#define SIZE 80
#define FLAFS O_RDWR|O_APPEND

int main(void)
{
	int count;
	int fd;
	char write_buf[SIZE];
	const char *pathname = FILENAME;
	if((fd=open(pathname, FLAFS)) == -1){
		printf("error, open file error\n");
		exit(1);
	}
	printf("OK, open file successfully\n");
	printf("Begin write:\n");
	gets(write_buf);
	count = strlen(write_buf);
	if(write(fd, write_buf, count) == -1){
		printf("error, write file failed\n");
		exit(1);
	}
	printf("OK,write %d chars to file\n", count);
	return 0;
}
