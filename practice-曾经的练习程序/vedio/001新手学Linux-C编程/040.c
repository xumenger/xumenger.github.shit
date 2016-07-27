#include<string.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/msg.h>
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
		memset(&buf, 0, sizeof(buf));
		ret = msgrcv(qid, &buf, MSG_SZ, 0, 0);
		if(ret < 0){
			perror("msgrcv error");
			exit(1);
		}else{
			printf("Received message:\n");
			printf("Type=%d, Lenght=%d, Text=%s\n", buf.mtype, ret, buf.mtext);
		}
	}
	return 0;
}
