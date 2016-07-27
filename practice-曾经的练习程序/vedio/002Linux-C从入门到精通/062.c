#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>

#define PORT 5566

int main(void)
{
	int sockfd, newsockfd;
	struct sockaddr_in addr;
	char msgbuf[256];
	int addr_len = sizeof(struct sockaddr_in);
	if((sockfd=socket(AF_INET, SOCK_STREAM, 0))<0){
		perror("socket error\n");
		exit(1);
	}
	else{
		printf("socket success\n");
		printf("socket id : %d\n", sockfd);
	}
	bzero(&addr, sizeof(struct sockaddr_in));
	addr.sin_family = AF_INET;
	addr.sin_port = htons((PORT));
	addr.sin_addr.s_addr = htonl(INADDR_ANY);
	if(bind(sockfd, (struct sockaddr *)(&addr), sizeof(struct sockaddr))<0){
		perror("bind error\n");
		exit(1);
	}
	else{
		printf("bind success\n");
		printf("local port : %d\n", PORT);
	}
	if(listen(sockfd, 5)<0){
		perror("listen error\n");
		exit(1);
	}
	else
		printf("listening......\n");
	if((newsockfd=accept(sockfd, (struct sockaddr *)(&addr), &addr_len)<0))
		perror("accept error\n");
	else{
		printf("connect from %s\n", inet_ntoa(addr.sin_addr));
		if(read(newsockfd, msgbuf, sizeof(msgbuf))<=0)
			perror("accept error\n");
		else
			printf("message:\n %s\n", msgbuf);
	}
	return 0;
}
