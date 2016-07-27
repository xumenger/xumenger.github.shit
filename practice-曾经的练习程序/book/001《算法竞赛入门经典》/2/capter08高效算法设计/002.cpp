S[0] = 0;
for(i=0; i<=n; i++)
	S[i] = S[i-1]+A[i];

for(i=1; i<=n; i++)
	for(j=i; j<=n; j++)
		best>?=S[j]-S[i-1];
