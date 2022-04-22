#include <bits/stdc++.h>

using namespace std;

int main()
{
	int t, i, a, b;
	string s;
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> t;
	while(t--){
		cin >> s;
		
		a = b = 0;
		for(i=0; i<s.size(); i++){
			if(s[i] == 'a'){
				if(b == 1) break;
				a++;
				b = 0;
			}
			if(s[i] == 'b'){
				if(a == 1) break;
				b++;
				a = 0;
			}
		}
		
		if(a == 1 || b == 1) cout << "NO\n";
		else cout << "YES\n";
	}
	
	return 0;
}
