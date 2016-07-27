#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<string.h>

#define PORT 9999
#define MAX_MSG_SIZE 1024

int main(void)
{
	int sockfd, addrlen, n;
	struct sockaddr_in addr;
	char msg[MAX_MSG_SIZE];
	sockfd = socket(AF_INET, SOCK_DGRAM, 0);
	if(sockfd<0){
		fprintf(stderr, "Socket error: %s\n", strerror(errno));
		exit(1);
	}
	addrlen = sizeof(struct sockaddr_in);
	bzero(&addr, addrlen);
	addr.sin_family = AF_INET;
	addr.sin_addr.s_addr = htonl(INADDR_ANY);
	addr.sin_port = htons(PORT);
	if(bind(sockfd, (struct sockaddr *)(&addr), addrlen)<0){
		fprintf(stderr, "Bind Error: %s\n",strerror(errno));
		exit(1);
	}
	while(1){
		bzero(msg, MAX_MSG_SIZE);
		n = recvfrom(sockfd, msg, sizeof(msg), 0, (struct sockaddr *)(&addr), &addrlen);
		fprintf(stdout, "Receive message from client\n %s", msg);
		fgets(msg, MAX_MSG_SIZE, stdin);
		printf("Serber endpoint input message \n%s", msg);
		sendto(sockfd, msg, n, 0, (struct sockaddr *)(&addr), addrlen);
	}
	close(sockfd);
	return 0;
}
