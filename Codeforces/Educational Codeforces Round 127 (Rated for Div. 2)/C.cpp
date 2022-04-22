#include <bits/stdc++.h>

using namespace std;

int a[200010];

int main()
{
	int t, n, i;
	long long x, sum, ans;
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> t;
	while(t--){
		cin >> n >> x;
		for(i=0; i<n; i++) cin >> a[i];
		
		sort(a, a+n);
		
		sum = ans = 0;
		for(i=0; i<n; i++){
			sum += a[i];
			
			if(sum <= x) ans += (x-sum) / (i+1) + 1;
		}
		
		cout << ans << '\n';
	}
	
	return 0;
}
