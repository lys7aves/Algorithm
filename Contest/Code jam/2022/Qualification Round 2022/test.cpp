#include <bits/stdc++.h>

using namespace std;

int main()
{
	int i, n;
	double pr=1;
	
	cin >> n;
	
	for(i=0; i<n; i++){
		pr *= (n-i)/(double)n;
		
		if(pr < 0.5) break;
	}
	
	cout << i;
	
	return 0;
}
