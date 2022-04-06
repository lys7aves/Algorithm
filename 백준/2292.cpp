#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n, i, sum=1;
	
	cin >> n;
	for(i=0; i<n; i++){
		sum += i*6;
		if(n <= sum) break;
	}
	
	cout << i+1;
	
	return 0;
}
