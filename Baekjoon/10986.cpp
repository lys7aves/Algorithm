#include <bits/stdc++.h>

using namespace std;

int a[1000010], sum[1000010], cnt[1010];

int main()
{
	int n, m, i;
	long long ans=0;
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n >> m;
	
	cnt[0] = 1;
	for(i=1; i<=n; i++){
		cin >> a[i];
		sum[i] = (sum[i-1] + a[i]) % m;
		
		ans += cnt[sum[i]];
		cnt[sum[i]]++;
	}
	
	cout << ans;
	
	return 0;
}
