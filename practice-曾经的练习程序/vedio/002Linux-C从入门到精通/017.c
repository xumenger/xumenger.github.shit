#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define SIZE 30

int main(void)
{
	char newpath[SIZE];
	char buf[SIZE];
	printf("Input the new pathname(size<30):");
	gets(newpath);
	if(chdir(newpath)==-1){
		printf("error change directory\n");
		exit(1);
	}
	printf("OK,change success\n");
	if(getcwd(buf, SIZE)==NULL){
		printf("getcwd error\n");
		exit(1);
	}
	printf("cwd = %s\n", buf);
	return 0;
}
