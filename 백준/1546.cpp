#include <iostream>

using namespace std;

int main()
{
	int n, i, a, sum=0, maxi=0;
	
	cin >> n;
	for(i=0; i<n; i++){
		cin >> a;
		
		sum += a;
		maxi = max(maxi, a);
	}
	
	cout << sum * 100.0 / n / maxi;
	
	return 0;
}
