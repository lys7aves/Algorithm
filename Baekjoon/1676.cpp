#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n, i, ans=0;
	
	cin >> n;
	for(i=5; i<=n; i*=5) ans += n/i;
	
	cout << ans;
	
	return 0;
}
