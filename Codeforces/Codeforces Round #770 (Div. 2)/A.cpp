#include <iostream>
#include <string>

using namespace std;

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string s;
	int t, n, k, i;
	
	cin >> t;
	while(t--){
		cin >> n >> k;
		cin >> s;
		
		for(i=0; i<n; i++){
			if(s[i] != s[n-i-1]) break;
		}
		
		if(i < n && k > 0) cout << 2 << '\n';
		else cout << 1 << '\n';
	}
	
	return 0;
}
