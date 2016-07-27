/*
 * 编写一个程序，从标准输入读取几行输入。每行输入都要打印到标准输出上，前面要加上行号。
 * 在编写这个程序时要试图让程序能够处理的输入行的长度没有限制
 */
/*
 * 通过从输入逐字符读取而不是逐行读取，可以避免长度限制。在这个解决方案中，如果定义了TRUE
 * 和FALSE符号，程序的可读性就会更好一些。
 */
#include<stdio.h>
#include<stdlib.h>

int main()
{
	int ch;
	int line;
	int at_beginning;

	line = 0;
	at_beginning = 1;

	/*
	 * 读取字符并逐个处理
	 */
	while((ch = getchar()) != EOF){
		/*
		 * 如果我们位于一行的起始位置，打印行号
		 */
		if( at_beginning == 1 ){
			at_beginning = 0;
			line += 1;
			printf("%d ", line);
		}
		/*
		 * 打印字符， 并对行尾进行检查
		 */
		putchar(ch);
		if( ch == '\n' )
			at_beginning = 1;
	}
	
	return EXIT_SUCCESS;
}
