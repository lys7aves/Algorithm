#include <bits/stdc++.h>

using namespace std;

bool chk[10010];

int main()
{
	int t, i, j, n;
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	chk[0] = chk[1] = true;
	for(i=2; i<=10000; i++){
		if(chk[i]) continue;
		for(j=i+i; j<=10000; j+=i) chk[j] = true;
	}
	
	cin >> t;
	while(t--){
		cin >> n;
		
		for(i=n/2; i>=2; i--){
			if(chk[i]) continue;
			if(chk[n-i]) continue;
			cout << i << ' ' << n-i << '\n';
			break;
		}
	}
	
	return 0;
}
