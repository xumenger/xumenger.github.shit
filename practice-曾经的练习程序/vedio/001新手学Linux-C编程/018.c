#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<error.h>

int main(int argc, char **argv)
{
	int ret;
	if(argc != 3){
		printf("too few arguements\n");
		exit(1);
	}
	ret = symlink(argv[1], argv[2]);
	if(ret == -1){
		perror("symlink failed");
		exit(1);
	}
	printf("Done!\n");

	return 0;
}
