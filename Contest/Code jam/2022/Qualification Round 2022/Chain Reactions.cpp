#include <bits/stdc++.h>

#define MAXN 100010
#define MAXF 1000000000

using namespace std;

long long ans;
int f[MAXN], max_f[MAXN];
vector<int> edge[MAXN];

void dfs(int v);

int main()
{
	int T, C, n, i, p;
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> T;
	for(C=1; C<=T; C++){
		cout << "Case #" << C << ": ";
		
		cin >> n;
		for(i=1; i<=n; i++) cin >> f[i];
		for(i=1; i<=n; i++){
			cin >> p;
			edge[p].push_back(i);
		}
		
		ans = 0;
		dfs(0);
		ans += max_f[0];
		
		cout << ans << '\n';
		
		for(i=0; i<=n; i++) edge[i].clear();
	}
	
	return 0;
}

void dfs(int v)
{
	int i, u, mini=MAXF;
	long long sum=0;
	
	for(i=0; i<edge[v].size(); i++){
		u = edge[v][i];
		
		dfs(u);
		
		sum += max_f[u];
		mini = min(mini, max_f[u]);
	}
	
	if(edge[v].size()){
		ans += sum - mini;
		max_f[v] = max(f[v], mini);
	}
	else{
		max_f[v] = f[v];
	}
}
