#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<errno.h>
#include<string.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<sys/socket.h>

#include"cpumem.h"

#define SERV_PORT 2395
#define BUF_SIZE 1024

int main(int argc, char **argv)
{
	int ret;
	int sockfd;
	struct sockaddr_in serv_addr;
	char buf[BUF_SIZE];
	struct cpustatus cpu_stat;
	struct meminfo mem_info;
	int cnt;
	int size;
	if(argc != 2){
		printf("arguements error\n");
		exit(1);
	}
	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if(-1 == sockfd){
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
	cnt = recv(sockfd ,buf, BUF_SIZE, 0);
	if(-1 == cnt){
		perror("recv error\n");
		exit(1);
	}
	size = sizeof(struct cpustatus);
	memcpy(&cpu_stat, buf, size);
	memcpy(&mem_info, buf+size, sizeof(struct meminfo));
	printf("\n %.2f\n%s\n", cpu_stat.user, mem_info.free);

	close(sockfd);
	return 0;
}
