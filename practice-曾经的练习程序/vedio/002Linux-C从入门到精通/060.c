#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>

#define PORT 80
#define REMOTE_IP "119.75.213.61"

int main(void)
{
	int sockfd;
	struct sockaddr_in addr;
	if((sockfd = socket(AF_INET, SOCK_STREAM, 0))<0){
		perror("socket error\n");
		exit(1);
	}
	else{
		printf("socket created success\n");
		printf("socket id : %d\n", sockfd);
	}
	bzero(&addr, sizeof(struct sockaddr_in));
	addr.sin_family = AF_INET;
	addr.sin_port = htons(PORT);
	addr.sin_addr.s_addr = inet_addr(REMOTE_IP);

	if(connect(sockfd, (struct sockaddr *)(&addr), sizeof(struct sockaddr))<0){
		perror("connect error\n");
		exit(1);
	}
	else{
		printf("connect success\n");
	}
	return 0;
}
