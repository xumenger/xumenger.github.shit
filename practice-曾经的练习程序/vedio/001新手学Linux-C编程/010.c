#include<stdio.h>
#include<string.h>

int main()
{
	char str[] = "Linux C Programming";
	char *p;
	p = strtok(str, " ");
	while(p != NULL){
		printf("%s\n", p);
		p= strtok(NULL, " ");
	}
	printf("%s\n", str);

	return 0;
}
