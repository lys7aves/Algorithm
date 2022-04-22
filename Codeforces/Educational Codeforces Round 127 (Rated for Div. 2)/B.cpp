#include <bits/stdc++.h>

#define MAXN 200010

using namespace std;

int x[MAXN];

int main()
{
	int t, n, i, l;
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> t;
	while(t--){
		cin >> n;
		
		for(i=0; i<n; i++) cin >> x[i];
		
		l = x[0]+1;
		for(i=1; i<n; i++){
			if(l+i == x[i]-1) continue;
			if(l+i == x[i]) continue;
			if(l+i == x[i]+1) continue;
			break;
		}
		
		if(i<n) cout << "NO\n";
		else cout << "YES\n";
	}
	
	return 0;
}
