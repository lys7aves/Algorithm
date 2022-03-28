#include <bits/stdc++.h>

using namespace std;

int main()
{
	int t, n, i, ans;
	string s;
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> t;
	while(t--){
		cin >> n;
		cin >> s;
		
		ans = 0;
		if(s[1] == '0' && s[0] == '0') ans = 2;
		for(i=2; i<n; i++){
			if(s[i] == '1') continue;
			
			if(s[i-1] == '0') ans += 2;
			else if(s[i-2] == '0') ans ++;
		}
		
		cout << ans << '\n';
	}
	
	return 0;
}
