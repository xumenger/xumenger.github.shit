#include<stdio.h>
#define N 5

struct student
{
	int id;
	int score;
} stu[N];

int main()
{
	struct student *pt, *p[N];
	int i, j, k, sum = 0;
	printf("Please input ID and score:\n");
	for(i=0; i<=N-1; i++){
		scanf("%d%d", &stu[i].id, &stu[i].score);
		p[i] = &stu[i];
		sum += stu[i].score;
	}
	for(i=0; i<=N-2; i++){
		k = i;
		for(j=i; j<=N-1; j++){
			if(p[k]->score < p[j]->score){
				k = j;
			}
		}
		if(k != i){
			pt = p[i];
			p[i] = p[k];
			p[k] = pt;
		}
	}
	printf("ID Score\n");
	printf("---------------------------\n");
	for(i=0; i<N-1; i++){
		printf("%d %d\n", (*p[i]).id, p[i]->score);
	}
	printf("Average score = %d\n", sum/N);

	return 0;
}
