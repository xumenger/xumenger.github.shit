#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
/*定义flags：只写，文件不存在则创建、文件长度截短为0*/
#define FLAGS O_WRONLY|O_CREAT|O_TRUNC
/*创建文件的权限：用户读写、执行；组读、执行；其他用户读、执行*/
#define MODE S_IRWXU|S_IRGRP|S_IXGRP|S_IROTH|S_IXOTH

int main(void)
{
	const char *pathname;
	int fd;
	char pn[30];
	printf("Input the pathname(<30 chars):");
	gets(pn);
	pathname = pn;
	if((fd=open(pathname, FLAGS, MODE))==-1){
		printf("error, open file failed\n");
		exit(1);
	}
	printf("OK, open file successfully\n");
	printf("fd=%d\n", fd);
	return 0;
}
