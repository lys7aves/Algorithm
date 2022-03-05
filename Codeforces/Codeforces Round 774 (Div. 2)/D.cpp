#include <iostream>
#include <vector>

#define MAXN 200010
using namespace std;

int dp_cnt[2][MAXN], dp_sum[2][MAXN], color[MAXN], ans[MAXN];
vector<int> edge[MAXN];

void dp_dfs(int u, int p);
void color_dfs(int u, int p);

int main()
{
	int n, i, u, v, cnt=0;
	long long sum=0;
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n; 
	for(i=0; i<n-1; i++){
		cin >> u >> v;
		
		edge[u].push_back(v);
		edge[v].push_back(u);
	}
	
	if(n == 2){
		cout << "2 2\n";
		cout << "1 1";
		return 0;
	}
	
	dp_dfs(1, 0);
	
	if(dp_cnt[0][1] == dp_cnt[1][1]) color[1] = dp_sum[0][1] < dp_sum[1][1] ? 0 : 1;
	else color[1] = dp_cnt[0][1] > dp_cnt[1][1] ? 0 : 1;
	
	color_dfs(1, 0);
	
	for(i=1; i<=n; i++){
		cnt += color[i];
		ans[i] = color[i] ? edge[i].size() : 1;
		sum += ans[i];
	}
	
	cout << cnt << ' ' << sum << '\n';
	for(i=1; i<=n; i++) cout << ans[i] << ' ';
	
	//cout << '\n';
	//for(i=1; i<=n; i++) cout << color[i] << ' ';
	
	return 0;
}

void dp_dfs(int u, int p)
{
	int v, i, cnt0=0, cnt_max=0, sum0=0, sum_max=0;
	
	//cout << u << ' ' << p << '\n';
	
	for(i=0; i<edge[u].size(); i++){
		v = edge[u][i];
		if(v == p) continue;
		dp_dfs(v, u);
		
		cnt0 += dp_cnt[0][v];
		sum0 += dp_sum[0][v];
		
		if(dp_cnt[0][v] > dp_cnt[1][v]){
			cnt_max += dp_cnt[0][v];
			sum_max += dp_sum[0][v];
		}
		else if(dp_cnt[0][v] < dp_cnt[1][v]){
			cnt_max += dp_cnt[1][v];
			sum_max += dp_sum[1][v];
		}
		else if(dp_cnt[0][v] == dp_cnt[1][v]){
			cnt_max += dp_cnt[0][v];
			sum_max += min(dp_sum[0][v], dp_sum[1][v]);
		}
	}
	
	dp_cnt[0][u] = cnt_max;
	dp_sum[0][u] = sum_max+1;
	
	dp_cnt[1][u] = cnt0+1;
	dp_sum[1][u] = sum0+edge[u].size();
	
	//cout << u << ' ' << dp_cnt[0][u] << ' ' << dp_sum[0][u] << ' ' << dp_cnt[1][u] << ' ' << dp_sum[1][u] << '\n';
}

void color_dfs(int u, int p)
{
	int v, i;
	
	for(i=0; i<edge[u].size(); i++){
		v = edge[u][i];
		if(v == p) continue;
		
		if(color[u] == 1) color[v] = 0;
		else{
			if(dp_cnt[0][v] == dp_cnt[1][v]) color[v] = dp_sum[0][v] < dp_sum[1][v] ? 0 : 1;
			else color[v] = dp_cnt[0][v] > dp_cnt[1][v] ? 0 : 1;
		}
		
		color_dfs(v, u);
	}
}
