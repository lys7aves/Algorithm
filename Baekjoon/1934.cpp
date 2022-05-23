#include <bits/stdc++.h>

using namespace std;

int main()
{
	int t, a, b, i, gcd;
	
	cin >> t;
	while(t--){
		cin >> a >> b;
		
		for(i=1; i<=a; i++){
			if(a%i == 0 && b%i == 0) gcd = i;
		}
		
		cout << a*b/gcd << '\n';
	}
	
	return 0;
}
