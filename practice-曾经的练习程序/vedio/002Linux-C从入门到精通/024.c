#include<stdio.h>
#include<stdlib.h>

int main(int argc, char **argv)
{
	if(argc != 3){
		printf("arguement count error\n");
		exit(1);
	}
	FILE *fp1, *fp2;
	char buf[1024];
	int n;
	if((fp1=fopen(argv[1], "rb"))==NULL){
		printf("fail to open src file\n");
		exit(1);
	}
	if((fp2=fopen(argv[2], "wb"))==NULL){
		printf("fail to open des file\n");
		exit(1);
	}

	while((n=fread(buf, sizeof(char), 1024, fp1))>0){
		if(fwrite(buf, sizeof(char), n, fp2)==-1){
			printf("fail to write\n");
			exit(1);
		}
	}
	if(n == -1){
		printf("fail to read\n");
		exit(1);
	}
	fclose(fp1);
	fclose(fp2);

	return 0;
}
