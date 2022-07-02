#include <bits/stdc++.h>

using namespace std;

int cnt[2];
bool color[200][200];

void dfs(int x, int y, int l)
{
	int i, j;
	
	for(i=0; i<l; i++){
		for(j=0; j<l; j++){
			if(color[x][y] != color[x+i][y+j]) break;
		}
		if(j < l) break;
	}
	if(i < l){
		dfs(x, y, l/2);
		dfs(x, y+(l/2), l/2);
		dfs(x+(l/2), y, l/2);
		dfs(x+(l/2), y+(l/2), l/2);
	}
	else{
		cnt[color[x][y]]++;
	}
}

int main()
{
	int n, i, j;
	
	cin >> n;
	for(i=0; i<n; i++){
		for(j=0; j<n; j++){
			cin >> color[i][j];
		}
	}
	
	dfs(0,0,n);
	
	cout << cnt[0] << '\n' << cnt[1];
	
	return 0;
}
