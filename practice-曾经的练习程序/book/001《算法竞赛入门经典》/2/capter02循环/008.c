#include<stdio.h>

#define INF 10000000

int main(){
	FILE *fin, *fout;
	fin = fopen("data.in", "rb");
	fout = fopen("data.out", "wb");

	int n=0, s=0, i=0;
	int min = INF;
	int max = -INF;

	while(fscanf(fin, "%d", &i)==1){
		s+=i;
		if(i<min)
			min=i;
		if(i>max)
			max=i;
		n++;
	}
	fprintf(fout,"%d %d %lf\n", min, max, (double)s/n);
	fclose(fin);
	fclose(fout);

	return 0;
}
