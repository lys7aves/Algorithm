#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n, k, i, ans=1;
	
	cin >> n >> k;
	
	for(i=1; i<=n; i++) ans *= i;
	for(i=1; i<=k; i++) ans /= i;
	for(i=1; i<=n-k; i++) ans /= i;
	
	cout << ans;
	
	return 0;
}
