#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int data;
	struct node *next;
} Stack;



int main()
{
	int x;
	Stack *top = (Stack *)malloc(sizeof(Stack));
	StackInit(top);
	printf("input some positive integers:\n");
	scanf("%d", &x);

	while(x > 0){
		Push(top, x); 
		scanf("%d", &x);
	}
	while(Pop(top, &x)){
		printf("%d", x);
	}
	printf("\n");

	return 0;
}
