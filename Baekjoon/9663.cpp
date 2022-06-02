#include <bits/stdc++.h>

using namespace std;

int n, cnt;
bool board[20][20];

void dfs(int p)
{
	int i, j;
	
	if(p == n){
		cnt++;
		return;
	}
	
	for(i=0; i<n; i++){
		for(j=0; j<=p; j++){
			if(board[j][i]) break;
			if(i-j >=0 && board[p-j][i-j]) break;
			if(i+j < n && board[p-j][i+j]) break;
		}
		
		if(j <= p) continue;
		
		board[p][i] = true;
		dfs(p+1);
		board[p][i] = false;
	}
}

int main()
{
	cin >> n;
	
	dfs(0);
	
	cout << cnt;
	
	return 0;
}
