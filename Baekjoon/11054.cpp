#include <bits/stdc++.h>

using namespace std;

int s[1010], icrs[1010], dcrs[1010];

int main()
{
	int n, i, j, ans=0;
	
	cin >> n;
	for(i=0; i<n; i++) cin >> s[i];
	
	for(i=0; i<n; i++){
		for(j=0; j<i; j++){
			if(s[j] < s[i]){
				icrs[i] = max(icrs[i], icrs[j]+1);
			}
		}
	}
	for(i=n-1; i>=0; i--){
		for(j=i; j<n; j++){
			if(s[i] > s[j]){
				dcrs[i] = max(dcrs[i], dcrs[j]+1);
			}
		}
	}
	
	for(i=0; i<n; i++){
		ans = max(ans, icrs[i]+dcrs[i]+1);
	}
	
	cout << ans;
	
	return 0;
}
