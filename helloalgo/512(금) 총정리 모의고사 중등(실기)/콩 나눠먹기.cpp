#include <iostream>

using namespace std;

int dp[500][500][500], sum[500][500][500];

int main()
{
	int n, k, i, j, l;
	
	cin >> n >> k;
	
	dp[0][0][0] = 1;
	for(i=0; i<=n; i++) sum[0][0][i] = 1;
	
	for(i=1; i<=n; i++){
		for(j=1; j<=k; j++){
			for(l=1; l<=n; l++){
				if(l <= i) dp[i][j][l] = sum[i-l][j-1][l];
				sum[i][j][l] = sum[i][j][l-1] + dp[i][j][l];
			}
		}
	}
	
	cout << sum[n][k][n];
	
	return 0;
}