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

int main(int argc, char **argv)
{
	int sockfd, port, addrlen, n;
	char buffer[MAX_MSG_SIZE];
	struct sockaddr_in addr;
	if(argc != 3){
		fprintf(stderr, "Usage : %s server_ip server_port\n",argv[0]);
		exit(1);
	}
	if((port=atoi(argv[2]))<0){
		fprintf(stderr, "Usage : %s server_ip server_port\n", argv[0]);
		exit(1);
	}
	sockfd = socket(AF_INET, SOCK_DGRAM, 0);
	if(sockfd<0){
		fprintf(stderr, "Socket Errot :%s\n", strerror(errno));
		exit(1);
	}
	addrlen = sizeof(struct sockaddr_in);
	bzero(&addr, addrlen);
	addr.sin_family = AF_INET;
	addr.sin_port = htons(port);
	if(inet_aton(argv[1], &addr.sin_addr)<0){
		fprintf(stderr, "IP error : %s\n", strerror(errno));
		exit(1);
	}
	while(1){
		bzero(buffer, MAX_MSG_SIZE);
		fgets(buffer, MAX_MSG_SIZE, stdin);
		sendto(sockfd, buffer, strlen(buffer)+1, 0, (struct sockaddr *)(&addr), addrlen);
		printf("Client endpoint input message\n %s", buffer);
		n = recvfrom(sockfd, buffer, MAX_MSG_SIZE, 0, (struct sockaddr *)(&addr), &addrlen);
		fprintf(stdout, "Receive message from server\n %s", buffer);
	}
	close(sockfd);
	return 0;
}
