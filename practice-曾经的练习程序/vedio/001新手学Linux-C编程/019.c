#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/stat.h>

int main(int argc, char ** argv)
{
	struct stat st;
	if(argc != 2){
		printf("too few arguements.\n");
		exit(1);
	}
	stat(argv[1], &st);
	printf("File Size: %ld Byte\n", st.st_size);
	printf("File Type: ");
	switch(st.st_mode & S_IFMT){
		case S_IFSOCK:
			printf("Socket\n");
			break;
		case S_IFLNK:
			printf("Symbolic link\n");
			break;
		case S_IFREG:
			printf("Regular file\n");
			break;
		case S_IFDIR:
			printf("Directory\n");
			break;
		case S_IFCHR:
			printf("Character device\n");
			break;
		case S_IFIFO:
			printf("FIFO\n");
			break;
		default:
			;
	}
	return 0;
}
