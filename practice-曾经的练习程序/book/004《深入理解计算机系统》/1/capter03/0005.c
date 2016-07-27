int fix_prod_ele(fix_matrix A, fix_matrix B, int i, int k){
	int j;
	int result = 0;
	for(j=0; j<N; j++)
		result += A[i][j] * B[j][k];

	return result;
}

int fix_prod_ele(fix_matrix A, fix_matrix B, int i, int k){
	int *Arow = &A[i][0];
	int *Brow = &B[0][k];

	int result = 0;
	int j;
	for(j=0; j!=N; j++){
		result += Arow[j] * (*Brow);
		Brow += N;
	}
	return result;
}
