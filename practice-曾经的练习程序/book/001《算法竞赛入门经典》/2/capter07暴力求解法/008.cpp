int dfs(int cur){
	if(cnt++ == n){
		for(int i=0; i<cur; i++)
			printf("%c", 'A'+S[i]);
		printf("\n");
		return 0;
	}
	for(int i=0; i<L; i++){
		S[cur] = i;
		int ok = 1;
		for(int j=0; j*2<=cur+1; j++){
			int equal = 1;
			for(int k=0; k<j; k++)
				if(S[cur-k]!=S[cur-k-j]){
					equal = 0;
					break;
				}
			if(equal){
				ok = 0;
				break;
			}
		}
	}
	return 1;
}
