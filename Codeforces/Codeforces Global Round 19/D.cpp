#include <iostream>
#include <stdio.h>

#define MAXN 110
#define MAX 10010

using namespace std;

int n, mini;
int a[MAXN], b[MAXN], a_[MAXN], b_[MAXN], pre[MAXN][2*MAX];
bool visit[MAXN][2*MAX], who[MAXN][2*MAX];

void dfs(int i, int x);
void delete_dfs(int i, int x);

int main()
{
	int t, i, x;
	long long ans, sum_a, sum2_a, sum_b, sum2_b;
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> t;
	while(t--){
		cin >> n;
		for(i=1; i<=n; i++) cin >> a[i];
		for(i=1; i<=n; i++) cin >> b[i];
		
		mini = 2*MAX;
		dfs(0, MAX);
		
		x = mini;
		for(i=n; i>=1; i--){
			if(who[i][x]){
				a_[i] = a[i];
				b_[i] = b[i];
			}
			else{
				a_[i] = b[i];
				b_[i] = a[i];
			}
			
			x = pre[i][x];
		}
		
		delete_dfs(0, MAX);
		
		sum_a = sum2_a = sum_b = sum2_b = 0;
		for(i=1; i<=n; i++){
			sum_a += a_[i];
			sum2_a += a_[i] * a_[i];
			sum_b += b_[i];
			sum2_b += b_[i] * b_[i];
		}
		
		cout << sum_a*sum_a + (n-2)*sum2_a + sum_b*sum_b + (n-2)*sum2_b << '\n';
	}
	
	return 0;
}

void dfs(int i, int x)
{
	if(i == n){
		if(x < MAX) return;
		
		mini = min(mini, x);
		return;
	}
	
	int diff = a[i+1]-b[i+1];
	
	if(!visit[i+1][x+diff]){
		visit[i+1][x+diff] = true;
		pre[i+1][x+diff] = x;
		who[i+1][x+diff] = true;
		
		dfs(i+1, x+diff);
	}
	if(!visit[i+1][x-diff]){
		visit[i+1][x-diff] = true;
		pre[i+1][x-diff] = x;
		who[i+1][x-diff] = false;
		
		dfs(i+1, x-diff);
	}
}

void delete_dfs(int i, int x)
{
	if(i == n) return;
	
	int diff = a[i+1]-b[i+1];
	
	if(visit[i+1][x+diff]){
		visit[i+1][x+diff] = false;
		delete_dfs(i+1, x+diff);
	}
	if(visit[i+1][x-diff]){
		visit[i+1][x-diff] = false;
		delete_dfs(i+1, x-diff);
	}
}
