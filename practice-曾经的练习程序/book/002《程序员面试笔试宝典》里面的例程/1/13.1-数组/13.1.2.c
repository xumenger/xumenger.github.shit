/*
 *如何用一个for循环打印出一个二维数组，函数为MAXX，列数为MAXY
 */
/*
 *如果使用双重for循环，会很容易打印二维数组，但是本题要求只能使用一次，所以就需要明白二维数组在内存中是按照行还是按照列
 *存储的（默认是按照行），所以可以将数组array看成一个一维数组，i标识该数在一维数组中的位置，则array在二维数组中的行号和
 *列号分别是[i/MAXY]，[i%MAXY]
 */
#include<stdio.h>

#define MAXX 2
#define MAXY 3

void printArray(){
	int array[MAXX][MAXY]={1,2,3,4,5,6};
	int i=0;	//任何变量在定义的时候，最好先初始化一个值，我在乐易面试的时候吃过这个亏
	for(i=0; i<MAXX*MAXY; i++){
		printf("%d ",array[i/MAXY][i%MAXY]);
	}
	printf("\n");
}

int main(){
	printArray();
	return 0;
}
