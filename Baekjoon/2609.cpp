#include <bits/stdc++.h>

using namespace std;

int main()
{
	int a, b, i, gcd=1;
	
	cin >> a >> b;
	
	for(i=1; i<=a; i++){
		if(a%i == 0 && b%i == 0) gcd = i;
	}
	
	cout << gcd << '\n';
	cout << a * b / gcd;
	
	return 0;
}
