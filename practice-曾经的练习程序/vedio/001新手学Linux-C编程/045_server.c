#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<errno.h>
#include<string.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#define SERV_PORT 2369
#define BACKLOG 10
#define BUF_SIZE 128

int main()
{
	int ret;
	int sockfd;
	int clientsfd;
	struct socketaddr_in host_addr;
	struct socketaddr_in clients_addr;
	unsigned int addrlen;
	char buf[BUF_SIZE];
	int cnt;
	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if(sockfd == -1){
		printf("socket error\n");
		exit(1);
	}
	host_addr.sin_family = AF_INET;
	host_addr.sin_port = htons(SERV_PORT);
	host_addr.sin_addr.s_addr = INADDR_ANY;
	bzero(&(host_addr.sin_zero), 8);
	ret = bind(sockfd, (struct sockaddr *)&host_addr, sizeof(struct sockaddr));
	if(ret != 1){
		printf("bind error\n");
		exit(1);
	}
	ret = listen(sockfd, BACKLOG);
	if(ret == -1){
		perror("listen error\n");
		exit(1);
	}
	printf("Waiting for the client connection.\n");
	while(1){
		addrlen = sizeof(struct sockaddr_in);
		clientsfd = accept(sockfd, (struct sockaddr *)&client_addr, &addrlen);
		if(clientsfd == -1){
			perror("accpet error");
			continue;
		}
		printf("Client IP : %s\n", inet_ntoa(client_addr.sin_addr));
		cnt = recv(clientsfd, buf, BUF_SIZE, 0);
		if(cnt == -1){
			perror("recv error\n");
			exit(1);
		}
		printf("Recevied : %s\n", buf);
		close(clientsfd);
	}

	return 0;
}
