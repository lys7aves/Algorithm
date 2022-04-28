#include <bits/stdc++.h>

using namespace std;

int main()
{
	int a, b, c, maxi;
	
	while(1){
		cin >> a >> b >> c;
		if(a == 0 && b == 0 && c == 0) break;
		
		maxi = max(a, max(b, c));
		if(a*a+b*b+c*c == 2*maxi*maxi) cout << "right\n";
		else cout << "wrong\n";
	}
	return 0;
}
