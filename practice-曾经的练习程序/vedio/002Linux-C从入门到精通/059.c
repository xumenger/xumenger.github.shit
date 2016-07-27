#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>

#define PORT 2345

int main(void)
{
	int sockfd, newsockfd;
	struct sockaddr_in addr;
	int addr_len = sizeof(struct sockaddr_in);
	if((sockfd = socket(AF_INET, SOCK_STREAM, 0))<0){
		perror("socket error\n");
		exit(1);
	}
	else{
		printf("socket success\n");
		printf("socket id : %d\n", sockfd);
	}
	bzero(&addr, sizeof(struct sockaddr_in));
	addr.sin_family = AF_INET;
	addr.sin_port = htons(PORT);
	addr.sin_addr.s_addr = htonl(INADDR_ANY);
	if(bind(sockfd, (struct sockaddr *)(&addr), sizeof(struct sockaddr))<0){
		perror("bind error\n");
		exit(1);
	}
	else{
		printf("bind success\n");
		printf("local port : %d\n", PORT);
	}
	if(listen(sockfd, 3)<0){
		perror("listen error\n");
		exit(1);
	}
	else{
		printf("listening........\n");
	}
	if((newsockfd = accept(sockfd, (struct sockaddr *)(&addr), &addr_len))<0)
		perror("accept error\n");
	else{
		printf("accept a new connection\n");
		printf("new socket id : %d\n", newsockfd);
	}
	return 0;
}
