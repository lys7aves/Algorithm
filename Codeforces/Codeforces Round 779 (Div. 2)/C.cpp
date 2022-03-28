#include <bits/stdc++.h>

using namespace std;

int c[100010];

int main()
{
	int t, n, i, idx1, j, j_;
	bool flag;
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> t;
	while(t--){
		cin >> n;
		
		idx1 = -1;
		for(i=0; i<n; i++){
			cin >> c[i];
			if(c[i] == 1) idx1 = i;
		}
		
		if(idx1 == -1){
			cout << "NO\n";
			continue;
		}
		
		flag = true;
		for(i=1; i<n; i++){
			j = (idx1+i)%n;
			j_ = (j-1+n)%n;
			
			if(c[j] == 1) flag = false;
			if(c[j] > c[j_] && c[j] != c[j_]+1) flag = false;
		}
		
		if(flag) cout << "YES\n";
		else cout << "NO\n";
	}
	
	return 0;
}
