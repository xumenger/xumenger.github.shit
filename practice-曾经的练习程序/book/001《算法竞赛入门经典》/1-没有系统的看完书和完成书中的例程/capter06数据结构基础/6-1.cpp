/*
 *桌上有一叠牌，从第一张（即位于顶面的牌）开始从上到下依次编号是1～n。当至
 *少还剩2张牌时进行一下操作：把第一张牌扔掉，然后把新的第一张牌放到整叠牌的
 *最后。
 *输入n
 *输出每次扔掉的牌，以及最后剩下的牌
 *
 *用C++中的队列数据类型来实现这个功能
 *
 *例子：输入7,输出1 3 5 7 4 2 6
 */
#include<stdio.h>
#include<queue>
using namespace std;

queue<int> q;	//注意C++中队列对象的定义

int main(){
	int n;
	scanf("%d",&n);
	for(int i=0; i<n; i++)
		q.push(i+1);	//初始化队列
	while(!q.empty()){
		printf("%d ", q.front());	//打印队首元素
		q.pop();					//抛弃队首元素
		q.push(q.front());			//将抛弃原来队首元素之后的新的队首元素加到队尾
		q.pop();					//抛弃队首元素
	}
	printf("\n");
	return 0;
}
