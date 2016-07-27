#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>

#define PORT 21
#define REMOTE_IP "140.186.70.20"

int main(void)
{
	int sockfd;
	struct sockaddr_in addr;
	char buf[256];
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
	addr.sin_addr.s_addr = inet_addr(REMOTE_IP);
	if(connect(sockfd, (struct sockaddr *)(&addr), sizeof(struct sockaddr))<0){
		perror("connect error\n");
		exit(1);
	}
	else{
		printf("connect success\n");
		printf("remote ip : %s\n", REMOTE_IP);
		printf("remote port : %d\n", PORT);
	}

	recv(sockfd, buf, sizeof(buf), 0);
	printf("%s\n", buf);
	
	return 0;
}
