#include<stdio.h>
#include<stdlib.h>

int main()
{
	system("ps -o pid,ppid,comm ");
	system("ls");
	return 0;
}
