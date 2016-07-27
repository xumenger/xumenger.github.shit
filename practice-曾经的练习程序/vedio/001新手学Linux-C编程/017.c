#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<error.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<sys/types.h>
#define BUFFER_SIZE 256

int main(int argc, char **argv)
{
	int fd1, fd2;
	int cntr, cntw;
	char buffer[BUFFER_SIZE];
	char *ptr;
	if(argc != 3){
		printf("too few arguements,\n");
		exit(1);
	}
	fd1 = open(argv[1], O_RDONLY);
	if(fd1 == -1){
		perror("open file1 failed");
		exit(1);
	}
	fd2 = open(argv[2], O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR);
	if(fd2 == -1){
		perror("open file2 failed");
		exit(1);
	}
	while((cntr = read(fd1, buffer, BUFFER_SIZE)) != 0){
		if(cntr == -1){
			perror("read error");
			break;
		}else if(cntr > 0){
			ptr = buffer;
			while((cntw = write(fd2, ptr, cntr)) != 0){
				if(cntw == -1){
					perror("write error");
					break;
				}else if(cntw == cntr){
					break;
				}else if(cntw > 0){
					ptr += cntw;
					cntr -= cntw;
				}
			}
			if(cntw == -1){
				break;
			}
		}
	}
	close(fd1);
	close(fd2);
	printf("Copy Success!\n");
	
	return 0;
}
