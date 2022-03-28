#include <bits/stdc++.h>

#define MOD 998244353

using namespace std;

int main()
{
	int t, n, i;
	long long ans;
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> t;
	while(t--){
		cin >> n;
		
		if(n%2 == 1) cout << "0\n";
		else{
			ans = 1;
			for(i=1; i<=n/2; i++) ans = (ans*i)%MOD;
			
			cout << (ans*ans)%MOD << '\n';
		}
	}
	
	return 0;
}
