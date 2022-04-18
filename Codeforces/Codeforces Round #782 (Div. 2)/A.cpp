#include <bits/stdc++.h>

using namespace std;

int main()
{
	int t, n, r, b, i, j;
	
	cin >> t;
	while(t--){
		cin >> n >> r >> b;
		
		for(i=0; i<b; i++){
			for(j=0; j<r/(b+1-i); j++) cout << 'R';
			cout << 'B';
			
			r -= r/(b+1-i);
		}
		for(j=0; j<r; j++) cout << 'R';
		cout << '\n';
	}
	
	return 0;
}
