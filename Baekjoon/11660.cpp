#include <bits/stdc++.h>

using namespace std;

int sum[1030][1030];

int main()
{
	int n, m, i, j, x, x1, y1, x2, y2;
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n >> m;
	for(i=1; i<=n; i++){
		for(j=1; j<=n; j++){
			cin >> x;
			sum[i][j] = sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1] + x;
		}
	}
	
	while(m--){
		cin >> x1 >> y1 >> x2 >> y2;
		
		cout << sum[x2][y2] - sum[x1-1][y2] - sum[x2][y1-1] + sum[x1-1][y1-1] << '\n';
	}
	
	return 0;
}
