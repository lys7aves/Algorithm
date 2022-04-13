#include <bits/stdc++.h>

using namespace std;

int ans[15][15];

int main()
{
	int t, k, n, i, j;
	
	for(i=0; i<=14; i++){
		for(j=1; j<=14; j++){
			if(i == 0) ans[i][j] = j;
			else ans[i][j] = ans[i][j-1] + ans[i-1][j];
		}
	}
	
	cin >> t;
	while(t--){
		cin >> k >> n;
		cout << ans[k][n] << '\n';
	}
	
	return 0;
}
