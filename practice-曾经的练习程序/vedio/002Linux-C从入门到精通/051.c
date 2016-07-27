#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

void msg_stat(int, struct msqid_ds);

int main(void)
{
	int gflags, sflags, rflags;
	key_t key;
	int msgid;
	int reval;
	struct msgsbuf{
		int mtype;
		char mtext[1];
	}msg_sbuf;
	struct msgmbuf{
		int mtype;
		char mtext[10];
	}msg_rbuf;
	struct msqid_ds msg_ginfo, msg_sinfo;
	char *msgpath = "/unix/msgqueue";
	key = =ftok(msgpath, 'a');
	gflags = IPC_CERAT | IPC_EXCL;
	msgid = msgget(key, gflags|00666);
	if(msgid=-1){
		printf("msg create error\n");
		return;
	}
	msg_stat(msgid, msg_ginfo);
	sflag = IPC_NOWAIT;
	msg_sbuf.mtype = 10;
	msg_sbuf.mtext[0]='a';
	reval = msgsnd(msgid, &msg_sbuf, sizeof(msg_sbuf.mtext), sflags);
	if(reval == -1)
		printf("message send error\n");
	msg_stat(msgid, msg_ginfo);
	rflags = IPC_NOWAIT | MSG_NOERROR;
	reval = msgrcv(msgid, &msg_rbuf, 4, 10, rflags);
	if(reval == -1)
		printf("read error\n");
	else
		printf("%d \n", reval);
	msg_stat(msgid, msg_ginfo);
	msg_sinfo.msg_perm.uid=8;
	msg_sinfo.msg_perm.gid=8;
	msg_sinfo.msg_qbytrs=16388;
	reval = msgctl(msgid, IPC_SET, &msg_sinfo);
	if(reval==-1){
		printf("msg set info error\n");
		exit(1);
	}
	msg_stat(msgid, msg_ginfo);
	reval = msgctl(msgid, IPC_RMID, NULL);
	if(reval == -1){
		printf("unlink msg queue error\n");
		return;
	}
	return 0;
}

void msg_stat(int msgid, struct msqid_ds msg_info)
{
	int reval;
	sleep(1);
	reval = msgctl(msgid, IPC_STAT, &msg_info);
	if(reval == -1){
		printf("get msg info error\n");
		return;
	}
	printf("\n current number of bytes on queue is %d\n", msg_info.msg_cbytes);
	printf(number of message in queue is %d\n, msg_info.mag_qnum);

}
