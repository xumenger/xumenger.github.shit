#include<stdio.h>
#include<stdlib.h>

int main(int argc, char **argv)
{
	if(argc!=3){
		printf("arguement count error\n");
		exit(1);
	}

	/*注意命令行参数的使用*/
	char *src = argv[1];	/*正确的*/	
	/*char src[] = argv[1];	错误的*/
	char *des = argv[2];	/*同上*/

	FILE *fp1, *fp2;
	int c ;
	printf("%s %s\n", src, des);

	if((fp1=fopen(src, "rd"))==NULL){
		printf("fail to open src file\n");
		exit(1);
	}
	if((fp2=fopen(des, "wb"))==NULL){
		printf("fail to open des file\n");
		exit(1);
	}

	while((c=fgetc(fp1))!=EOF){
		if(fputc(c, fp2)==EOF){
			printf("fail to write\n");
			exit(1);
		}
		if(fputc(c, stdout)==EOF){
			printf("fail to write\n");
			exit(1);
		}
	}
	fclose(fp1);
	fclose(fp2);

	return 0;
}
