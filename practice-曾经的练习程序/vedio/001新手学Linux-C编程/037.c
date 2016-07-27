#include<stdio.h>
#include<signal.h>

int main()
{
	int i;
	alarm(1);
	i = 0;
	while(1){
		printf("i = %d\n", i);
		i++;
	}
	return 0;
}
