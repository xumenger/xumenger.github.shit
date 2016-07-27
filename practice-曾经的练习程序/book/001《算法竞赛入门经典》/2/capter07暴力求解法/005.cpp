void search(int cur){
	int i, j;
	if(cur == n)
		tot++;
	else
		for(i=0; i<n; i++){
			if(!vis[0][i] && !vis[1][cur+i] && !vis[2][cur-i+n]){
				C[cur] = i;
				vis[0][i] = vis[1][cur+i] = vis[2][cur-i+n] =1;
				search(cur+1);
				vis[0][i] = vis[1][cur+i] = vis[2][cur-i+n] = 0;
			}
		}
}
