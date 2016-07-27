#include<stdio.h>
#include<stdlib.h>

int main()
{
	FILE * fp;
	int ch;
	fp = fopen("./tmp", "w+");
	if(fp == NULL){
		perror("Open tmp failed");
		exit(1);
	}
	while((ch = getchar()) != '!'){
		fputc(ch, fp);
	}
	rewind(fp);
	while((ch = fgetc(fp)) != EOF){
		putchar(ch);
	}
	fclose(fp);
	return 0;
}
