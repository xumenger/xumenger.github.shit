#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct line{
	int length;
	char contents[0];
};

int main(){
	int this_length = 10;
	struct line *thisline = (struct line *)malloc(sizeof(struct line) + this_length);
	thisline->length = this_length;
	memset(thisline->contents, 'a', this_length);
	return 0;
}
