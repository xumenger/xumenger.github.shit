#include<string.h>
#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	char *s = "hello";
	printf("%s\n", s);
	printf("%s\n", &s[1]);

	return 0;
}
