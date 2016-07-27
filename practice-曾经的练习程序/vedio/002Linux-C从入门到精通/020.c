#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>

int main(void)
{
	FILE *fp;
	int fd;
	if((fp=fopen("./test", "r+"))==NULL){
		printf("fail to open!\n");
		exit(1);
	}
	fprintf(fp, "Hello! I like Linux C program!\n");
	fclose(fp);

	if((fd=open("./test", O_RDWR))==-1){
		printf("fail to open!\n");
		exit(1);
	}
	if((fp=fdopen(fd, "a+"))==NULL){
		printf("fail to open!\n");
		exit(1);
	}
	fprintf(fp, "I am doing linux C program!\n");
	fclose(fp);
	return 0;
}
