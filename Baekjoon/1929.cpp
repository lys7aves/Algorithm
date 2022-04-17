#include <bits/stdc++.h>

#define MAX 1000000

using namespace std;

bool chk[MAX+1];

int main()
{
	int m, n, i, j;
	
	chk[1] = true;
	for(i=2; i<=MAX; i++){
		if(chk[i]) continue;
		for(j=i+i; j<=MAX; j+=i) chk[j] = true;
	}
	
	cin >> m >> n;
	for(i=m; i<=n; i++){
		if(!chk[i]) cout << i << '\n';
	}
	
	return 0;
}
