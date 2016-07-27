#include<stdio.h>
#include<stdlib.h>
#define BUFFER_SIZE 10

int main()
{
	char buffer[BUFFER_SIZE];
	int c;
	FILE *fp;
	fp = fopen("./026.c", "r");
	if(fp == NULL){
		perror("Open 026.c failed");
		exit(1);
	}
	c = 1;
	while(fgets(buffer, BUFFER_SIZE, fp) != NULL){
		printf("%d: %s", c++, buffer);
	}
	fclose(fp);

	return 0;
}
