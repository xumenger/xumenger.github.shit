#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<error.h>
#define BUFFER_SIZE 64

int main()
{
	int ret;
	char buf[BUFFER_SIZE];
	getcwd(buf, sizeof(buf));
	printf("%s\n", buf);
	ret = chdir("./joker");
	if(ret == -1){
		perror("chdir error");
		exit(1);
	}
	getcwd(buf, sizeof(buf));
	printf("%s\n", buf);
	return 0;
}
