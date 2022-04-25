#include <bits/stdc++.h>

#define MAX 1000000000
#define MAXN 1010

using namespace std;

int X[MAXN][2];
long long dp[MAXN][2];

int main()
{
	int T, C, n, p, i, j, x;
	
	cin >> T;
	for(C=1; C<=T; C++){
		cin >> n >> p;
		for(i=1; i<=n; i++){
			X[i][0] = MAX;
			X[i][1] = 0;
			for(j=0; j<p; j++){
				cin >> x;
				X[i][0] = min(X[i][0], x);
				X[i][1] = max(X[i][1], x);
			}
		}
		
		for(i=1; i<=n; i++){
			int gap = X[i][1] - X[i][0];
			
			dp[i][0] = min(dp[i-1][0]+abs(X[i-1][0]-X[i][1]), dp[i-1][1]+abs(X[i-1][1]-X[i][1])) + gap;
			dp[i][1] = min(dp[i-1][0]+abs(X[i-1][0]-X[i][0]), dp[i-1][1]+abs(X[i-1][1]-X[i][0])) + gap;
		}
		
		cout << "Case #" << C << ": ";
		cout << min(dp[n][0], dp[n][1]) << '\n';
	}
	
	return 0;
}
