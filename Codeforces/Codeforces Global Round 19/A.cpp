#include <iostream>

using namespace std;

int main()
{
	int t, n, a, maxi;
	bool ans;
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> t;
	while(t--){
		cin >> n;
		
		ans = false;
		maxi = 0;
		while(n--){
			cin >> a;
			if(a < maxi) ans = true;
			maxi = a;
		}
		
		if(ans) cout << "YES\n";
		else cout << "NO\n";
	}
	
	return 0;
}
