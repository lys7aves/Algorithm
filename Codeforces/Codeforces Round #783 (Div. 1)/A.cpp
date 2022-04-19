#include <bits/stdc++.h>

#define MAXN 5010

using namespace std;

int a[MAXN];

int main()
{
	int n, i, j;
	long long cnt, ans=-1, prev, x;
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n;
	for(i=0; i<n; i++){
		cin >> a[i];
	}
	
	for(i=0; i<n; i++){
		cnt = prev = 0;
		for(j=i+1; j<n; j++){
			x = prev/a[j] + 1;
			cnt += x;
			prev = x*a[j];
		}
		prev = 0;
		for(j=i-1; j>=0; j--){
			x = prev/a[j] + 1;
			cnt += x;
			prev = x*a[j];
		}
		if(ans==-1 || ans>cnt) ans = cnt;
	}
	
	cout << ans;
	
	return 0;
}
