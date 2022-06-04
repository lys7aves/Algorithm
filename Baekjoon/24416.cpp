#include <bits/stdc++.h>

using namespace std;

int fibo[50];

int main()
{
	int n, i;
	
	cin >> n;
	
	fibo[1] = fibo[2] = 1;
	for(i=3; i<=n; i++) fibo[i] = fibo[i-1] + fibo[i-2];
	
	cout << fibo[n] << ' ' << n-2;
	
	return 0;
}
