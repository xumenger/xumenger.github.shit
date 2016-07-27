void search(int cur){
	int i, j;
	if(cur == n)
		tot++;
	else
		for(i=0; i<n; i++){
			int ok = 1;
			C[cur] = i;
			for(j=0; j<cur; j++)
				if(C[cur]==C[j] || cur-C[cur]==j-C[cur] || cur+C[cur]==j+C[j]){
					ok = 0; 
					break;
				}
			if(ok)
				search()cur+1;
		}
}
