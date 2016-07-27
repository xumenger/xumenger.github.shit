#include<stdio.h>
void A(int i);
void B(int i);

void A(int i){
	B(i);
	i++;
	if(i>100)
		return ;
	printf("A调用B\n");
}
void B(int i){
	A(i);
	i++;
	printf("B调用A\n");
}

int main(){
	int i=0;
	
	A(i);

	return 0;
}
