#include <iostream>
#include <queue>

using namespace std;

int ans[110][110];
char maze[110][110];
queue<int> que;

int main()
{
	int n, m, i, j, k, x, y, z, sx, sy;
	
	cin >> n >> m;
	for(i=0; i<n; i++){
		for(j=0; j<m; j++){
			cin >> maze[i][j];
			if(maze[i][j] == 'S'){
				sx = i;
				sy = j;
				maze[i][j] = '.';
			}
		}
	}
	
	for(i=0; i<n; i++){
		for(j=0; j<m; j++){
			if(maze[i][j] == 'C'){
				for(k=i; maze[k][j] != 'W'; k++) if(maze[k][j] == '.') ans[k][j] = -1;
				for(k=i; maze[k][j] != 'W'; k--) if(maze[k][j] == '.') ans[k][j] = -1;
				for(k=j; maze[i][k] != 'W'; k++) if(maze[i][k] == '.') ans[i][k] = -1;
				for(k=j; maze[i][k] != 'W'; k--) if(maze[i][k] == '.') ans[i][k] = -1;
			}
		}
	}
	
	que.push(sx); que.push(sy); que.push(1);
	while(!que.empty()){
		x = que.front(); que.pop();
		y = que.front(); que.pop();
		z = que.front(); que.pop();
		
		if(ans[x][y]) continue;
		if(maze[x][y] == 'W') continue;
		
		while(maze[x][y] != '.' && ans[x][y]==0){
			ans[x][y] = z;
			if(maze[x][y] == 'L') y--;
			else if(maze[x][y] == 'R') y++;
			else if(maze[x][y] == 'U') x--;
			else if(maze[x][y] == 'D') x++;
		}
		
		if(ans[x][y]) continue;
		ans[x][y] = z;
		
		que.push(x-1); que.push(y); que.push(z+1);
		que.push(x+1); que.push(y); que.push(z+1);
		que.push(x); que.push(y-1); que.push(z+1);
		que.push(x); que.push(y+1); que.push(z+1);
	}
	
	maze[sx][sy] = 'S';
	for(i=0; i<n; i++){
		for(j=0; j<m; j++){
			if(maze[i][j] == '.') cout << max(ans[i][j]-1,-1) << '\n';
		}
	}
	
	return 0;
}