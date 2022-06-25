#include <bits/stdc++.h>

using namespace std;

int main()
{
	int t, n, z, i, a, maxi;
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> t;
	while(t--){
		cin >> n >> z;
		
		maxi = 0;
		for(i=0; i<n; i++){
			cin >> a;
			maxi = max(maxi, a | z);
		}
		
		cout << maxi << '\n';
	}
	
	return 0;
}
