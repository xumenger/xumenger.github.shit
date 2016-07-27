#include<stdio.h>

int main()
{
	int red, yellow, green;
	printf("red yellow green\n");
	for(red=0; red<=3; red++)
		for(yellow=0; yellow<=3; yellow++)
			for(green=2; green<=6; green++)
				if(red+yellow+green == 8)
					printf("%d	%d	%d\n", red, yellow, green);

	return 0;
}
