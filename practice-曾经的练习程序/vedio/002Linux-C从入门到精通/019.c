#include<stdio.h>
#include<stdlib.h>
#define SIZE 1024
int main(void)
{
	char buf[SIZE];
	if(setvbuf(stdin, buf, _IONBF, SIZE) != 0){
		printf("error!\n");
		exit(1);
	}
	printf("OK, set successfully\n");
	printf("stdin is ");
	if(stdin->_flags & _IO_UNBUFFERED)
		printf("unbeffered\n");
	else if(stdin->_flags & _IO_LINE_BUF)
		printf("line-buffered\n");
	else 
		printf("fully-buffered\n");
	printf("buffered size is %ld\n", stdin->_IO_buf_end - stdin->_IO_buf_base);
	printf("file discriptor is %d \n\n", fileno(stdin));
	
	if(setvbuf(stdin, buf, _IOFBF, SIZE) != 0){
		printf("error\n");
		exit(1);
	}
	printf("OK, change successfully");
	printf("stdin is ");
	if(stdin->_flags & _IO_UNBUFFERED)
		printf("unbuffered\n");
	else if(stdin->_flags & _IO_LINE_BUF)
		printf("line-buffered\n");
	else
		printf("fully-buffered\n");
	printf("buffer size is %ld\n", stdin->_IO_buf_end - stdin->_IO_buf_base);
	printf("file discriptor is %d\n\n", fileno(stdin));

	return 0;
}
