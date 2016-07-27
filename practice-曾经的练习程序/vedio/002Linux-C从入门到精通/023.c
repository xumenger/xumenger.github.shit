#include<stdio.h>

int main(void)
{
	char buf[2048];
	while(gets(buf) == buf){
		printf("%s\n", buf);
	}

	return 0;
}
