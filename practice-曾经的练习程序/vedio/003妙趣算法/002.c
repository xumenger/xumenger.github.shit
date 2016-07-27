#include<stdio.h>
#include<math.h>

int main()
{
	long l = 0;
	int i;
	for(i=0; i<64; i++)
		l = l + pow(2, i+1);

	printf("%ld\n", l);
	return 0;
}
