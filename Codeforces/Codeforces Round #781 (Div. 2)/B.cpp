#include <bits/stdc++.h>

using namespace std;

map<int,int> m;

int main()
{
	int t, n, i, a, maxi, cnt;
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> t;
	while(t--){
		cin >> n;
		for(i=0; i<n; i++){
			cin >> a;
			
			if(m.find(a) == m.end()) m[a] = 0;
			m[a]++;
		}
		
		maxi = 0;
		for(auto it: m){
			maxi = max(maxi, it.second);
		}
		
		cnt = 0;
		while(maxi < n){
			cnt++; // copy
			cnt += maxi;
			maxi *= 2;
		}
		
		cout << cnt-(maxi-n) << '\n';
		
		m.clear();
	}
	
	return 0;
}
