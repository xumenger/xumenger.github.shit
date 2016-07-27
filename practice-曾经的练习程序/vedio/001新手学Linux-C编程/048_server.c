#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<errno.h>
#include<string.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<sys/socket.h>
#include<arpa/inet.h>

#include"cpumem.h"

#define SERV_PORT 2395
#define BACKLOG 10
#define BUF_SIZE 1024

void get_cpu_status(struct cpustatus *);
void get_mem_info(struct meminfo *);

int main()
{
	int ret;
	int pid;
	int sockfd;
	int clientsfd;
	struct sockaddr_in host_addr;	//本机的IP地址和端口号信息
	struct sockaddr_in client_addr;	//客户端IP地址和端口号信息
	unsigned int addrlen;
	char buf[BUF_SIZE];
	struct cpustatus cpu_stat;
	struct meminfo mem_info;
	int cnt;
	int size;

	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if(-1 == sockfd){
		printf("socket error\n");
		exit(1);
	}

	/*将套接字和IP地址与端口号绑定*/
	host_addr.sin_family = AF_INET;
	host_addr.sin_port = htons(SERV_PORT);
	host_addr.sin_addr.s_addr = INADDR_ANY;
	bzero(&(host_addr.sin_zero), 8);
	ret = bind(sockfd, (struct sockaddr *)&host_addr, sizeof(struct sockaddr));
	if(-1 == ret){
		printf("bind error\n");
		exit(1);
	}
	ret = listen(sockfd, BACKLOG);
	if(-1 == ret){
		perror("listen error\n");
		exit(1);
	}
	printf("Waiting for the client connection.\n");

	while(1){
		addrlen = sizeof(struct sockaddr_in);
		/*接受一个客户端连接*/
		clientsfd = accept(sockfd, (struct sockaddr *)&client_addr, &addrlen);
		if(-1 == clientsfd){
			perror("accept error\n");
			continue;
		}
		pid = fork();
		if(0 > pid){
			perror("fork error\n");
			exit(1);
		}
		if(0 == pid){
			close(sockfd);	//关闭父进程的套接字
			printf("Client IP : %s\n", inet_ntoa(client_addr.sin_addr));

			get_cpu_status(&cpu_stat);
			size = sizeof(struct cpustatus);
			memcpy(buf, &cpu_stat, size);

			get_mem_info(&mem_info);
			memcpy(buf+size, &mem_info, sizeof(struct meminfo));

			/*发送数据*/
			cnt = send(clientsfd, buf, BUF_SIZE, 0);
			if(-1 == cnt){
				perror("send error\n");
				exit(1);
			}
			printf("Done!\n");
			/*关闭当前客户端连接*/
			close(clientsfd);
			exit(0);
		}
		close(clientsfd);
	}
	return 0;
}

void get_cpu_status(struct cpustatus *cpu_stat)
{
	long total;
	float user, nice, system, idle;
	long cpu[21];
	char text[201];
	FILE *fp;
	fp = fopen("/proc/stat", "r");
	if(NULL == fp){
		printf("open stat failed\n");
		exit(1);
	}
	while(fgets(text, 200, fp) != NULL){
		if(strstr(text, "cpu")){
			sscanf(text, "%s %f %f %f %f", (char *)cpu, &user, &nice, &system, &idle);
		}
	}
	fclose(fp);

	total = user + nice + system + idle;
	user = (user/total) * 100;
	nice = (nice/total) * 100;
	system = (system/total) * 100;
	idle = (idle/total) * 100;

	cpu_stat->total = total;
	cpu_stat->user = user;
	cpu_stat->nice = nice;
	cpu_stat->system = system;
	cpu_stat->idle = idle;
	return ;
}

void get_mem_info(struct meminfo *minfo)
{
	int i, j;
	char total[MEM_SIZE];
	char free[MEM_SIZE];
	char temp[MEM_SIZE * 2];
	FILE * fp;
	fp = fopen("/proc/meminfo", "r");
	if(NULL == fp){
		printf("open meminfo failed\n");
		exit(1);
	}
	fgets(temp, MEM_SIZE * 2, fp);
	strcpy(total, temp);

	fgets(free, MEM_SIZE * 2, fp);
	strcpy(free, temp);
	fclose(fp);

	if(strlen(total) > 0){
		for(i=0, j=0; i<strlen(total); i++){
			if(isdigit(total[i]))
				minfo->total[j++] = total[i];
		}
		minfo->total[j] = '\0';
	}
	
	if(strlen(free) > 0){
		for(i=0, j=0;i<strlen(free); i++){
			if(isdigit(free[i])){
				minfo->free[j++] = free[i];
			}
			minfo->free[j] = '\0';
		}
	}
	return;
}
