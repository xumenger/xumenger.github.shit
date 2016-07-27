tot = 0;
best = A[1];
for(i=1; i<=n; i++){
	for(j=i; j<=n; j++){
		int sum = 0;
		for(k=i; k<=j; k++){
			sum = sum+A[k];
			tot++
		}
		if(sum>best)
			best = sum;
	}
}
