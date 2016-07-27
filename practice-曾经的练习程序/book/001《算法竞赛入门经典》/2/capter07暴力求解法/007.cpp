void dfs(int cur){
	if(cur==n && isp[A[0]+A[n-1]]){
		for(int i=0; i<n; i++)
			printf("%d ",A[i]);
		printf("\n");
	}
	else
		for(int i=0; i<=n; i++)
			if(!vis[i] && isp[i+A[cur-1]]){
				A[cur] = i;
				vis[i] = 1;
				dfs(cur +1);
				vis[i] = 0;
			}
}
