#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(int argc, char * argv[])
{
	int ch;
	if(argc < 2){
		printf("no arguements\n");
	}
	while((ch=getopt(argc, argv, "ac:c")) != -1){
		printf("optind : %d\n", optind);
		switch(ch){
			case 'a'
		}
	}
}
