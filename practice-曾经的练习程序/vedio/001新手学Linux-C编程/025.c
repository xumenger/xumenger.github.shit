#include<stdio.h>
#include<stdlib.h>
int main()
{
	FILE *fp;
	int i, ch, n;
	fp = fopen("./tmp", "r");
	if(fp == NULL){
		perror("Open tmp failed");
		exit(1);
	}
	for(i=0; i<=7; i+=2){
		fseek(fp, i, SEEK_SET);
		n = ftell(fp);
		printf("Position  : %ld\n", n+1);
		ch = fgetc(fp);
		printf("Character : ");
		putchar(ch);
		printf("\n");
	}
	fclose(fp);
	return 0;
}
