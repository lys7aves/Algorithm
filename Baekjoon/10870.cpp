#include <bits/stdc++.h>

using namespace std;

int fibo[21];

int main()
{
	int n, i;
	
	cin >> n;
	
	fibo[1] = 1;
	for(i=2; i<=n; i++) fibo[i] = fibo[i-1] + fibo[i-2];
	
	cout << fibo[n];
	
	return 0;
}
