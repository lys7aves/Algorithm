#include <bits/stdc++.h>

using namespace std;

int a[200010];

int main()
{
	int t, n, i;
	
	cin >> t;
	while(t--){
		cin >> n;
		for(i=0; i<n; i++) cin >> a[i];
		
		sort(a, a+n);
		
		if(a[n-1] - a[n-2] <= 1) cout << "YES\n";
		else cout << "NO\n";
	}
	
	return 0;
}
