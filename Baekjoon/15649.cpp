#include <bits/stdc++.h>

using namespace std;

int n, m;
int chk[10], ans[10];

void dfs(int p)
{
	int i;
	
	if(p == m){
		for(i=0; i<m; i++) cout << ans[i] << ' ';
		cout << '\n';
		return;
	}
	
	for(i=1; i<=n; i++){
		if(chk[i]) continue;
		
		ans[p] = i;
		chk[i] = true;
		dfs(p+1);
		
		chk[i] = false;
	}
}

int main()
{
	cin >> n >> m;
	
	dfs(0);
	
	return 0;
}
