#include<stdio.h>
#include<stdlib.h>

int main(int argc, char **argv)
{
	if(argc != 2){
		printf("arguement error\n");
		exit(1);
	}
	FILE *fp;
	char buf[] = "Hello Linux C";
	char buf2[80];
	if((fp = fopen(argv[1], "w"))==NULL){
		printf("fopen error\n");
		exit(1);
	}
	fprintf(fp, "%s", buf);
	fprintf(fp, "\n");
	fclose(fp);
	
	if((fp=fopen(argv[1], "r"))==NULL){
		printf("fopen error 2\n");
		exit(1);
	}
	fscanf(fp, "%s", buf2);
	//fscanf(fp, "%s", &buf2);
	fclose(fp);
	printf("%s", buf2);
	return 0;
}
