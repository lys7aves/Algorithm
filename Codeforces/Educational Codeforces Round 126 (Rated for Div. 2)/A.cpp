#include <bits/stdc++.h>

using namespace std;

int a[30], b[30];
int main()
{
	int t, n, i;
	long long ans;
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> t;
	while(t--){
		cin >> n;
		
		for(i=0; i<n; i++) cin >> a[i];
		for(i=0; i<n; i++) cin >> b[i];
		
		ans = 0;
		for(i=1; i<n; i++){
			ans += min(abs(a[i]-a[i-1])+abs(b[i]-b[i-1]), abs(a[i]-b[i-1])+abs(b[i]-a[i-1]));
		}
		
		cout << ans << '\n';
	}
	
	return 0;
}
