#include <stdio.h>
#include <queue>
#include <stack>

#define MAXN 1010

using namespace std;

int a[MAXN][MAXN], b[MAXN][MAXN];
queue<int> que;
stack<int> ans;

int main()
{
	int n, m, i, j, x, y, z, ii, jj, c;
	bool flag;
	
	scanf("%d %d", &n, &m);
	for(i=1; i<=n; i++){
		for(j=1; j<=m; j++){
			scanf("%d", &a[i][j]);
			b[i][j] = a[i][j];
		}
	}
	
	for(i=1; i<n; i++){
		for(j=1; j<n; j++){
			if(a[i][j] == a[i][j+1] && a[i][j] == a[i+1][j] && a[i][j] == a[i+1][j+1]){
				que.push(i);
				que.push(j);
				que.push(a[i][j]);
			}
		}
	}
	
	while(!que.empty()){
		x = que.front(); que.pop();
		y = que.front(); que.pop();
		z = que.front(); que.pop();
		
		flag = true;
		for(i=x; i<=x+1; i++){
			for(j=y; j<=y+1; j++){
				flag &= b[i][j] == 0;
			}
		}
		if(flag) continue;
		
		ans.push(z);
		ans.push(y);
		ans.push(x);
		
		b[x][y] = b[x+1][y] = b[x][y+1] = b[x+1][y+1] = 0;
		for(i=x-1; i<=x+1; i++){
			if(i <= 0 || i >= n) continue;
			for(j=y-1; j<=j+1; j++){
				if(j <= 0 || j >= m) continue;
				c = 0;
				for(ii=i; ii<=i+1; ii++){
					for(jj=j; jj<=j+1; jj++){
						if(b[ii][jj] != 0) c = b[ii][jj];
					}
				}
				if(c == 0) continue;
				
				flag = true;
				for(ii=i; ii<=i+1; ii++){
					for(jj=j; jj<=j+1; jj++){
						if(b[ii][jj] == 0) continue;
						flag &= b[ii][jj]==c;
					}
				}
				
				if(flag){
					que.push(i);
					que.push(j);
					que.push(c);
				}
			}
		}
	}
	
	flag = true;
	for(i=1; i<=n; i++){
		for(j=1; j<=m; j++){
			flag &= a[i][j] == 0;
		}
	}
	
	if(flag){
		printf("%d\n", ans.size());
		while(!ans.empty()){
			x = ans.top(); ans.pop();
			y = ans.top(); ans.pop();
			z = ans.top(); ans.pop();
			printf("%d %d %d\n", x, y, z);
		}
	}
	else printf("-1");
	
	return 0;
}
