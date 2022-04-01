#include <bits/stdc++.h>

using namespace std;

int main()
{
	int t, a, b;
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> t;
	while(t--){
		cin >> a >> b;
		
		if(a == 0) cout << 1 << '\n';
		else cout << a+2*b+1 << '\n';
	}
	
	return 0;
}
