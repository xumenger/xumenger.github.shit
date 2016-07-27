#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<errno.h>
#include<string.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<sys/socket.h>
#define SERV_PORT 2395
#define BUF_SIZE 1024
#define MEM_SIZE 32

struct cpustatus
{
	long total;
	float user;
	float nice;
	float system;
	float idle;
};
struct meminfo
{
	char total[MEM_SIZE];
	char free[MEM_SIZE];
};

int main(int argc, char ** argv)
{
	int ret;
	int sockfd;
	struct sockaddr_in serv_addr;
	char buf[BUF_SIZE];
	struct cpustatus cpu_stat;
	struct meminfo mem_info;
	int cnt;
	int size;
	if(2 != argc){
		printf("arguements error\n");
		exit(1);
	}
	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if(-1 ==sockfd){
		printf("socket error\n");
		exit(1);
	}
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_port = htons(SERV_PORT);
	serv_addr.sin_addr.s_addr = inet_addr(argv[1]);
	bzero(&(serv_addr.sin_zero), 8);
	ret = connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(struct sockaddr));
	if(-1 == ret){
		printf("connect error\n");
		exit(1);
	}
	cnt = recv(sockfd, buf, BUF_SIZE, 0);
	if(-1 ==cnt){
		perror("recv error\n");
		exit(1);
	}
	size = sizeof(struct cpustatus);
	memcpy(&cpu_stat, buf, size);
	memcpy(&mem_info, buf+size, sizeof(struct meminfo));
	
	printf("CPU Information\n");
	printf("--------------------------\n");
	printf("user :\t\t %.2f\%\n", cpu_stat.user);
	printf("nice :\t\t %.2f\%\N", cpu_stat.nice);
	printf("system :\t %.2f\%\n", cpu_stat.system);
	printf("idle :\t\t %.2f\%\n\n", cpu_stat.idle);
	printf("Memory Infotmation\n");
	printf("---------------------------\n");
	printf("total :\t\t %s kB\n", mem_info.total);
	printf("free:\t\t %s kB\n", mem_info.free);
	close(sockfd);

	return 0;
}
