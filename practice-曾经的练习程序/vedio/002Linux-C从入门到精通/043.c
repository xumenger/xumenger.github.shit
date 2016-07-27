int g_iSeq = 0;
void SignHandlerNew(int iSignNo, siginfo_t *pInfo, void *pReserved)
{
	int iSeq = g_iSeq++;
	printf("%d Enter SignHandlerNew, signo: %d\n", iSeq, iSignNo);
	sleep(3);
	printf("%d Leave SignHandlerNew, signo: %d\n",iSeq, iSignNo);
}

int main(void)
{
	char szBuf[20];
	int iRet;
	struct sigaction act;
	act.sa_signation = SignHandlerNew;
	act.sa_flags = SA_SIGINFO;

	sigset_t sigSet;
	sigemptyset(&sigSet);
	sigaddset(&sigSet, SIGINT);
	sigprocmask(SIG_BLOCK, &sigSet, NULL);
	sigemptyset(&act.sa_mask);
	sigaction(SIGINT, &act, NULL);
	sigaction(SIGQUIT, &act, NULL);

	do{
		iRet = read(STDIN_FILENO, szBuf, sizeof(szBuf)-1);
		if(iRet<0){
			perror("read fail");
			break;
		}
		szBuf[iRet] = 0;
		printf("Get: %s\n", szBuf);
	}while(strcmp(szBuf, "quit\n")!=0);

	return 0;
}
