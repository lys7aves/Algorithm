#include <bits/stdc++.h>

#define MAXN 200010
#define MAX 200000

using namespace std;

int a[MAXN];

int main()
{
	int t, n, x, i, mini, maxi;
	long long ans;
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> t;
	while(t--){
		cin >> n >> x;
		
		mini = MAX;
		maxi = 0;
		ans = 0;
		for(i=0; i<n; i++){
			cin >> a[i];
			
			mini = min(mini, a[i]);
			maxi = max(maxi, a[i]);
			
			if(i) ans += abs(a[i]-a[i-1]);
		}
		
		ans = min(ans+a[0]-1, min(ans+a[n-1]-1, ans+(mini-1)*2));
		x = max(maxi, x);
		ans = min(ans+x-a[0], min(ans+x-a[n-1], ans+(x-maxi)*2));
		
		cout << ans << '\n';
	}
	
	return 0;
}
