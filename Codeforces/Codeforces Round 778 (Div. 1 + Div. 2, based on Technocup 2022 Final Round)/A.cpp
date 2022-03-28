#include <bits/stdc++.h>

using namespace std;

int a[1010];

int main()
{
	int t, n, i;
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> t;
	while(t--){
		cin >> n;
		for(i=0; i<n; i++) cin >> a[i];
		
		sort(a, a+n);
		
		cout << a[n-1] + a[n-2] << '\n';
	}
	
	return 0;
}
