#include<stdio.h>
#include<stdlib.h>
#define SWN 3
#define FNAMELEN	80	/* 文件名最大字符数 */

char stuf[FNAMELEN];

int main()
{
	int i,j,n;
	char ch;
	FILE *fp;
	printf("Please input the students marks record file's name: ");
	scanf("%s",stuf);
	printf("%s\n", stuf);
	fp = fopen(stuf, "r");
	if(fp==NULL)
	{
		printf("The file %s doesn't exit, do you want to create it? (y/n) ", stuf);
		scanf("%c", &ch);
		if(ch =='Y'|| ch =='y')
		{
			fp=fopen(stuf,"w");
			printf("Please input the record number you want to write to the file: ");
			scanf("%d",&n);
			fclose(fp);
		}
	}
	else
		fclose(fp);
	puts("q : quit!");
	
	system("pause"); 
	return 0;
}
