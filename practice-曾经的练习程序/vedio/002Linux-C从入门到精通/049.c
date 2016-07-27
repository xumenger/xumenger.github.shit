#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<fcntl.h>
#include<time.h>	/*使用time()，ctime()等时间函数，要包含time.h头文件*/

#define BUFES PIPE_BUF

int main(void)
{
	int fd;
	int n, i;
	char buf[BUFES];
	time_t tp;
	printf("I am %d\n", getpid());
	if((fd=open("fifo1", O_WRONLY))<0){
		printf("Open error\n");
		exit(1);
	}
	for(i=0; i<10; i++){
		time(&tp);
		n = sprintf(buf, "write_fifo %d sends %s", getpid(), ctime(&tp));
		printf("Send msg: %s\n", buf);
		if((write(fd, buf, n+1))<0){
			printf("Write error\n");
			close(fd);
			exit(1);
		}
		sleep(3);
	}
	close(fd);
	exit(1);
}
