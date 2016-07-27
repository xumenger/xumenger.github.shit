#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>

int main(void)
{
	int count = 1;
	int child;
	printf("Before create son, the father's count is: %d\n", count);
	child = vfork();
	if(child < 0){
		printf("vfork error\n");
		exit(1);
	}
	if(child == 0){
		printf("This is son, his pid is: %d, and the count is : %d\n", getpid(), count++);
		exit(1);
	}
	else{
		printf("This is father, his pid is: %d, and the count is: %d\n", getpid(), count);
	}

	return 0;
}
