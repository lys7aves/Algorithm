#include <bits/stdc++.h>

using namespace std;

int main()
{
	int t, n, mini;
	
	cin >> t;
	while(t--){
		cin >> n;
		
		if(n < 100) cout << n%10 << '\n';
		else{
			mini = 9;
			for(; n; n/=10){
				mini = min(mini, n%10);
			}
			
			cout << mini << '\n';
		}
	}
	
	return 0;
}
