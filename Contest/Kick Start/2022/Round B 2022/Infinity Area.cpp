#include <bits/stdc++.h>

using namespace std;

int main()
{
	int T, C, r, a, b;
	double sum;
	
	cout << setprecision(16);
	
	cin >> T;
	for(C=1; C<=T; C++){
		
		cin >> r >> a >> b;
		
		sum = 0;
		while(r){
			sum += M_PI * r*r;
			sum += M_PI * r*r*a*a;
			
			r = r * a / b;
		}
		
		cout << "Case #" << C << ": ";
		cout << sum << '\n';
	}
	
	return 0;
}
