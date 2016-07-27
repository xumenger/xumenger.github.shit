#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<error.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<sys/types.h>

int main(int argc, char **argv)
{
	int ret;
	if(argc != 2){
		printf("too few arguements\n");
		exit(1);
	}
	ret = mkdir(argv[1], S_IRUSR | S_IXUSR);
	if(ret == -1){
		perror("mkdir error");
		exit(1);
	}
	printf("Done\n")	;
	return 0;
}
