#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<sys/types.h>
#include<sys/msg.h>
#include<sys/ipc.h>
#define MSG_SZ 128
struct msgbuf
{
	long mtype;
	char mtext[MSG_SZ];
};

int main()
{
	int qid;
	key_t key;
	int ret;
	struct msgbuf buf;
	key = ftok("./", "a");
	if(key < 0){
		perror("ftok error");
		exit(1);
	}
	qid = msgget(key, IPC_CREAT | 0666);
	if(qid < 0){
		perror("msgget error");
		exit(1);
	}
	while(1){
		printf("Input the message : ");
		fgets(buf.mtext, MSG_SZ, stdin);
		if(strncmp(buf.mtext, "exit", 4) == 0)
			break;
		buf.mtype = getpid();
		ret = msgsnd(qid, &buf, MSG_SZ, 0);
		if(ret < 0){
			perror("msgsnd error");
			exit(1);
		}else{
			printf("Send!\n");
		}
	}
	return 0;
}
