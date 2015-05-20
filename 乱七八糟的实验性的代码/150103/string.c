#include<stdio.h>

typedef struct string{
	char name[10];
}string;

int main()
{
	string name = "fuck";
	printf("%s\n", name);
	return 0;
}
