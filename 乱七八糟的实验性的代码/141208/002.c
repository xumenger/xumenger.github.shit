#include<stdio.h>
#include<assert.h>

#define TRUE 1
#define FALSE 0

int find_char(char **strings, int value);

int main(){
	char *strings[3] = {"abcdef", "ghijklmn", "opqrst"};

	int v = 'm';
	char **strs = strings;
	
	printf("%d\n", strs);

	printf("%d\n", find_char(strs, v));

	printf("%d\n", strs);

	return 0;
}

int find_char(char **strings, int value){
	//assert(strings != NULL);

	while(*strings != NULL){
		while(**strings != '\0'){
			if(*(strings)++ == value)
				return TRUE;
		}
		strings++;
	}
	return FALSE;
}
