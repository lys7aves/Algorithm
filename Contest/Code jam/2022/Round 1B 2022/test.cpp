#include <bits/stdc++.h>

using namespace std;

double p[9], p_[9];

int main()
{
	int i, T;
	double sum;
	
	for(i=1; i<9; i++) p[i] = 1/8.0;
	
	for(T=0; T<300; T++){
		for(i=0; i<9; i++) p_[i] = 0;
		p_[0] = p[0];
		p_[8] = p[8];
		
		for(i=1; i<8; i++){
			p_[i-1] += p[i]/2;
			p_[i+1] += p[i]/2;
		}
		
		sum = 0;
		for(i=0; i<9; i++){
			p[i] = p_[i];
			sum += p[i];
		}
		cout << T << ": " << sum << '\n';
	}
	
	for(i=0; i<9; i++) cout << i << ": " << p[i] << '\n';
	cout << p[0] + p[8];
	
	return 0;
}
