#include <bits/stdc++.h>

using namespace std;

void solve(int n, int s, int e)
{
	if(n == 0) return;
	
	int m = 6-s-e;
	
	solve(n-1, s, m);
	cout << s << ' ' << e << '\n';
	solve(n-1, m, e);
}

int main()
{
	int n;
	
	cin >> n;
	cout << (1<<n)-1 << '\n';
	
	solve(n, 1, 3);
	
	return 0;
}
