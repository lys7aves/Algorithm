#include <bits/stdc++.h>

using namespace std;

int main()
{
	int t, n, l, m, r, i, b, cnt;
	
	cin >> t;
	while(t--){
		cin >> n;
		
		l = 1; r = n;
		while(l < r){
			m = (l+r)/2;
			
			cout << "? " << l << ' ' << m << '\n';
			cout.flush();
			
			cnt = 0;
			for(i=l; i<=m; i++){
				cin >> b;
				if(l <= b && b <= m) cnt++;
			}
			
			if(cnt%2 == 0){
				l = m+1;
			}
			else{
				r = m;
			}
		}
		
		cout << "! " << l << '\n';
		cout.flush();
	}
	
	return 0;
}
