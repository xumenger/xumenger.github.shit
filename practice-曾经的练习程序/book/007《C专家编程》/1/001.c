#include<stdio.h>

int main(){
	char p[] = "abcdef";
	char* ptr = p;

	printf("%s\n", p);
	printf("%s\n", ptr);

	ptr[2] = 'z';
	ptr[3] = 'z';

	printf("%s\n", p);
	printf("%s\n", ptr);

	return 0;
}
