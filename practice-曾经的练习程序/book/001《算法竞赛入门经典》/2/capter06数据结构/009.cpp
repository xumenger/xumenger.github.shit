int q[MAXN*MAXN];

void bfs(int x, int y){
	inf front = 0;
	int rear = 0;
	int d, u;
	vis[x][y] = 1;
	fd[x][y] = u;
	dist[x][y] = 0;
	q[rear++] = u;
	while(front < rear){
		u = q[front++];
		x = u/m;
		y = u%m;
		for(d=0; d<4; d++){
			int nx = x+dx[d], ny = y+dy[d];
			if(nx>=0 && nx<x && ny>0 && ny<m && maze[nx][ny] && !vis[nx][ny]){
				int v = nx*m+ny;
				q[rear++] = v;
				vis[nx][ny] = 1;
				fa[nx][ny] = u;
				dist[nx][ny] = dist[x][y]+1;
				last_dir[nx][ny] = d;
			}
		}
	}
}
