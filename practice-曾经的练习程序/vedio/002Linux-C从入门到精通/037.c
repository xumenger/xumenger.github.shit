#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
#include<unistd.h>
#include<sys/types.h>

int g_iSeq = 0;
void SignHandlerNew(int iSignNo, siginfo_t *pInfo, void *pReserved)
{
	int iSeq = g_iSeq++;
	printf("%d Enter SignHandlerNew, signo : %d\n", iSeq, iSignNo);
	int i=0;
	for(i=0; i<3; i++){
		printf("do not kill me, please\n");
		sleep(1);
	}
	printf("%d leave SignHandlerNew, signo : %d\n", iSeq, iSignNo);
}

int main(void)
{
	char szBuf[20];
	int iRet;
	struct sigaction act;
	act.sa_sigaction = SignHandlerNew;
	act.sa_flags = SA_SIGINFO;
	sigemptyset(&act.sa_mask);
	sigaction(SIGINT, &act, NULL);
	sigaction(SIGQUIT, &act, NULL);
	do{
		iRet = read(STDIN_FILENO, szBuf, sizeof(szBuf)-1);
		if(iRet < 0){
			perror("read fail\n");
			break;
		}
		szBuf[iRet] = 0;
		printf("Get: %s", szBuf);
	}while(strcmp(szBuf, "quit\n")!=0)
;
	return 0;
}
