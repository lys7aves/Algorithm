#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n, m;
	long long i, cnt2=0, cnt5=0;
	
	cin >> n >> m;
	
	for(i=2; i<=n; i*=2) cnt2 += n/i;
	for(i=2; i<=m; i*=2) cnt2 -= m/i;
	for(i=2; i<=n-m; i*=2) cnt2 -= (n-m)/i;
	
	for(i=5; i<=n; i*=5) cnt5 += n/i;
	for(i=5; i<=m; i*=5) cnt5 -= m/i;
	for(i=5; i<=n-m; i*=5) cnt5 -= (n-m)/i;
	
	cout << min(cnt2, cnt5);
	
	return 0;
}
