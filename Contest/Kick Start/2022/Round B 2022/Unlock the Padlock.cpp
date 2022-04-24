#include <bits/stdc++.h>

#define MAXN 410

using namespace std;

int d;
int v[MAXN];
long long dp[MAXN][MAXN][2];
bool chk[MAXN][MAXN];

void solve(int l, int r);
int diff(int x, int y);

int main()
{
	int T, C, n, i, j, k;
	
	cin >> T;
	for(C=1; C<=T; C++){
		cin >> n >> d;
		for(i=0; i<n; i++){
			cin >> v[i];
		}
		
		for(i=0; i<n; i++){
			for(j=0; j<n; j++){
				for(k=0; k<2; k++){
					dp[i][j][k] = 0;
				}
				chk[i][j] = false;
			}
		}
		
		solve(0, n-1);
		
		long long _a, _b, ans;
		_a = dp[0][n-1][0] + diff(v[0], 0);
		_b = dp[0][n-1][1] + diff(v[n-1], 0);
		ans = min(_a, _b);
		
		cout << "Case #" << C << ": ";
		cout << ans << '\n';
	}
	
	return 0;
}

void solve(int l, int r)
{
	if(chk[l][r]) return;
	if(l == r){
		chk[l][r] = true;
		return;
	}
	
	solve(l+1, r);
	solve(l, r-1);
	
	long long _a, _b;
	// dp[l][r][0]
	_a = dp[l+1][r][0] + diff(v[l], v[l+1]);
	_b = dp[l+1][r][1] + diff(v[l], v[r]);
	dp[l][r][0] = min(_a, _b);
	
	// dp[l][r][1]
	_a = dp[l][r-1][0] + diff(v[r], v[l]);
	_b = dp[l][r-1][1] + diff(v[r], v[r-1]);
	dp[l][r][1] = min(_a, _b);
	
	chk[l][r] = true;
}

int diff(int x, int y)
{
	return min((x-y+d)%d, (y-x+d)%d);
}
