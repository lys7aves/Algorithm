#include <bits/stdc++.h>

#define MAXN (1<<17)+10

using namespace std;

int a[MAXN], cnt[20];

int main()
{
	int t, l, r, n, i, j, x;
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> t;
	while(t--){
		cin >> l >> r;
		n = r-l+1;
		
		for(i=0; i<n; i++){
			cin >> a[i];
			for(j=0; j<17; j++){
				if(a[i] & (1<<j)) cnt[j]++;
				else cnt[j]--;
			}
		}
		
		x = 0;
		for(i=0; i<17; i++){
			if(cnt[i] > 0) x |= 1<<i;
			cnt[i] = 0;
		}
		
		cout << x << '\n';
	}
	
	return 0;
}
