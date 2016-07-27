#include<stdio.h>
#include<stdlib.h>
int main()
{
	FILE *fp;
	fp = fopen("./010.c", "r");
	if(fp == NULL){
		printf("Open 010.c failed\n");
		exit(1);
	}
	printf("Open file succeed\n");
	fclose(fp);
	return 0;
}
