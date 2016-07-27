#include<stdio.h>
#include<string.h>

int main()
{
	char s[] = "Hello World";
	char *p;
	p = index(s, 'W');

	printf("%s\n", p);

	return 0;
}
