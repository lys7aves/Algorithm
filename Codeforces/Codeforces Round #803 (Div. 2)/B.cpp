#include <bits/stdc++.h>

using namespace std;

int a[200010];

int main()
{
	int t, n, k, i, cnt;
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> t;
	while(t--){
		cin >> n >> k;
		for(i=0; i<n; i++) cin >> a[i];
		
		if(k == 1) cout << (n-1)/2 << '\n';
		else{
			cnt = 0;
			for(i=1; i<n-1; i++){
				if(a[i] > a[i-1]+a[i+1]) cnt++;
			}
			
			cout << cnt << '\n';
		}
	}
	
	return 0;
}
