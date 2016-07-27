#include<stdio.h>

char ga[] = "abcdefghijklm";

void my_array_func(char* ca[10]){
	printf(" %#x \n", &ca);
	printf(" %#x \n", &(ca[0]));
	printf(" %#x \n", &(ca[1]));
}


int main(){
	printf("%#x\n", ga);

	my_array_func(ga);

	return 0;
}
