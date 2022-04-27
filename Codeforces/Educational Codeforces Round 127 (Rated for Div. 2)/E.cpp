#include <bits/stdc++.h>

#define MAXN ((1<<18)+10)
#define MAX 998244353

using namespace std;

string s;
long long dp[MAXN];
size_t hs[MAXN];
hash<string> str_hash;

void dfs(int i, int n);

int main()
{
	int n;
	
	cin >> n;
	cin >> s;
	
	dfs(1, n);
	
	cout << dp[1];
	
	return 0;
}

void dfs(int i, int n)
{
	if(n == 1){
		dp[i] = 1;
		hs[i] = str_hash(to_string(s[i-1]));
		return;
	}
	
	dfs(i*2, n-1);
	dfs(i*2+1, n-1);
	
	if(hs[i*2] == hs[i*2+1]) dp[i] = dp[i*2]*dp[i*2];
	else dp[i] = dp[i*2]*dp[i*2+1]*2;
	dp[i] %= MAX;
	
	string l, r;
	if(hs[i*2] < hs[i*2+1]){
		l = to_string(hs[i*2]);
		r = to_string(hs[i*2+1]);
	}
	else{
		l = to_string(hs[i*2+1]);
		r = to_string(hs[i*2]);
	}
	
	hs[i] = str_hash(l + s[i-1] + r);
}
