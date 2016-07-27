int maxsum(int* A, int x, int y){
	int i, m, v, L, R, max;
	if(y-x == 1)
		return A[x];

	m = x+(y-x)/2;
	max = maxsum(A, x, m)>? maxsum(A, m，y);
	v = 0;
	L = A[m-1];
	for(i=m-1; i>=x; i--)
		L>?=v+=A[i];
	v = 0;
	R = A[m];
	for(i=m; i<y; i++)
		R>?=v+=A[i];

	return max>?(L+R);
}
