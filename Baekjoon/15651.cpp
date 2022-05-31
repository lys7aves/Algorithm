#include <bits/stdc++.h>

using namespace std;

int n, m;
int ans[10];

void dfs(int p)
{
	int i;
	
	if(p == m){
		for(i=0; i<m; i++) cout << ans[i] << ' ';
		cout << '\n';
		
		return;
	}
	
	for(i=1; i<=n; i++){
		ans[p] = i;
		
		dfs(p+1);
	}
}

int main()
{
	cin >> n >> m;
	
	dfs(0);
	
	return 0;
}
