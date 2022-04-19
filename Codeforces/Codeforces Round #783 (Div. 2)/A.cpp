#include <bits/stdc++.h>

using namespace std;

int main()
{
	int t, n, m, ans;
	
	cin >> t;
	while(t--){
		cin >> n >> m;
		
		if(n == 1 && m == 1) cout << "0\n";
		else if(n == 1 || m == 1){
			if(n == 2 || m == 2) cout << "1\n";
			else cout << "-1\n";
		}
		else{
			ans = max(n-1, m-1) * 2;
			ans -= (n+m)%2;
			
			cout << ans << '\n';
		}
	}
	
	return 0;
}
