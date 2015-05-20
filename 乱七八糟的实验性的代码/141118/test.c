#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void newspace(char* c){
	c = (char*)malloc(50*sizeof(char));
	int i=0;

	for(i=0; i<49; i++)
		c[i] = 'a';
	c[49] = '\0';
}	

int main(){
	char *c;
//	printf("%d\n",sizeof(c));
	
//	newspace(c);
//	printf("%d\n",strlen(c)/sizeof(c[0]));
	
//	c = (char*)malloc(50*sizeof(char));
	newspace(c);

//	int i=0;
//	for(i=0; i<49; i++)
//		c[i] = 'a';
//	c[49] = '\0';
	printf("%s\n",c);

	return 0;
}
