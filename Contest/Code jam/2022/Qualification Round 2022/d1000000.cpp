#include <bits/stdc++.h>

#define MAXN 100010

using namespace std;

int s[MAXN];

int main()
{
	int T, C, n, i, cnt;
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> T;
	for(C=1; C<=T; C++){
		cout << "Case #" << C << ": ";
		
		cin >> n;
		for(i=0; i<n; i++) cin >> s[i];
		
		sort(s, s+n);
		
		cnt = 0;
		for(i=0; i<n; i++){
			if(s[i] >= cnt+1) cnt++;
		}
		
		cout << cnt << '\n';
	}
	
	return 0;
}
