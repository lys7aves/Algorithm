#include <bits/stdc++.h>

using namespace std;

int paper[3000][3000], cnt[3];

void dfs(int x, int y, int l)
{
	int i, j;
	
	for(i=x; i<x+l; i++){
		for(j=y; j<y+l; j++){
			if(paper[x][y] != paper[i][j]) break;
		}
		if(j < y+l) break;
	}
	
	if(i < x+l){
		for(i=x; i<x+l; i+=l/3){
			for(j=y; j<y+l; j+=l/3){
				dfs(i, j, l/3);
			}
		}
	}
	else{
		cnt[paper[x][y]+1]++;
	}
}

int main()
{
	int n, i, j;
	
	cin >> n;
	for(i=0; i<n; i++){
		for(j=0; j<n; j++){
			cin >> paper[i][j];
		}
	}
	
	dfs(0, 0, n);
	
	for(i=0; i<3; i++) cout << cnt[i] << '\n';
	
	return 0;
}
