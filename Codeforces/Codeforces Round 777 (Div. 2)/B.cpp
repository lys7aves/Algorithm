#include <stdio.h>
#include <algorithm>

#define MAXN 110

using namespace std;

int cnt, min_x, max_x, min_y, max_y;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int table[MAXN][MAXN], l[MAXN][MAXN], u[MAXN][MAXN];

void dfs(int x, int y)
{
	if(!table[x][y]) return;
	table[x][y] = 0;
	
	min_x = min(min_x, x);
	min_y = min(min_y, y);
	max_x = max(max_x, x);
	max_y = max(max_y, y);
	cnt++;
	
	for(int i=0; i<4; i++){
		dfs(x+dx[i], y+dy[i]);
	}
}

int main()
{
	int t, n, m, i, j;
	bool flag;
	
	scanf("%d", &t);
	while(t--){
		scanf("%d %d", &n, &m);
		for(i=1; i<=n; i++){
			for(j=1; j<=m; j++){
				scanf("%1d", &table[i][j]);
			}
		}
		
		flag = true;
		for(i=1; i<=n; i++){
			for(j=1; j<=m; j++){
				if(!table[i][j]) continue;
				
				cnt = 0;
				min_x = max_x = i;
				min_y = max_y = j;
				dfs(i, j);
				
				if(cnt != (max_x - min_x + 1) * (max_y - min_y + 1)) flag = false;
			}
		}
		
		if(flag) printf("YES\n");
		else printf("NO\n");
	}
	
	return 0;
}
