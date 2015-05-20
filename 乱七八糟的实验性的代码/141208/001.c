#include<stdio.h>

void int_plus(int i){
	i++;
}
void ptr_plus(int *i){
	i++;
}
void ptr2ptr_plus(int **i){
	i++;
}

int main(){
	int i = 0;
	int a[3] = {1, 2, 3};
	int aa[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

	int *ptr = a;
	int **ptr2ptr = aa;

	printf("%d\n", i);
	printf("%d\n", (int)ptr);
	printf("%d\n\n", (int)ptr2ptr);

	int_plus(i);
	printf("%d\n", i);

	ptr_plus(ptr);
	printf("%d\n", (int)ptr);

	ptr2ptr_plus(ptr2ptr);
	printf("%d\n\n", (int)ptr2ptr);


	return 0;
}
