#include <bits/stdc++.h>

using namespace std;

int sum[100010];

int main()
{
	int n, m, i, j;
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n >> m;
	for(i=1; i<=n; i++){
		cin >> j;
		sum[i] = sum[i-1] + j;
	}
	
	while(m--){
		cin >> i >> j;
		cout << sum[j] - sum[i-1] << '\n';
	}
	
	return 0;
}
