#include <bits/stdc++.h>

#define MAX 1000000007

using namespace std;

long long power(long long x, long long y)
{
	long long t;
	
	if(y == 0) return 1;
	
	t = power(x, y/2);
	
	if(y%2 == 0) return (t * t) % MAX;
	else return (((t * t) % MAX) * x) % MAX;
}

int main()
{
	int n, k, i;
	long long x=1, y=1;
	
	cin >> n >> k;
	
	for(i=n-k+1; i<=n; i++) x = (x*i) % MAX;
	for(i=1; i<=k; i++) y = (y*i) % MAX;
	
	y = power(y, MAX-2);
	
	cout << (x * y) % MAX;
	
	return 0;
}
