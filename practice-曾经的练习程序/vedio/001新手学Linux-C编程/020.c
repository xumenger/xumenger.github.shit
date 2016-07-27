#include<stdio.h>
#include<stdlib.h>
#include<error.h>
#include<sys/types.h>
#include<sys/stat.h>

int main(int argc, char **argv)
{
	int ret;
	if(argc != 2){
		printf("too few arguements\n");
		exit(1);
	}
	ret = chmod(argv[1], S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
	if(ret == -1){
		perror("chmod failed");
		exit(1);
	}
	printf("Done\n");
	return 0;
}
