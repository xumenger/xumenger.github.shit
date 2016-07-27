#include<stdio.h>
#include<time.h>	/*误将time.h写成sys/time.h，造成段错误*/
#define MAXN 1000

int main()
{
	time_t timep;
	time(&timep);
	printf("%s\n", ctime(&timep));

	return 0;
}
