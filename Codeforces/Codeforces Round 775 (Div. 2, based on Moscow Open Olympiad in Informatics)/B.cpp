#include <iostream>

using namespace std;

int main()
{
	int t, n, a, maxi, i;
	long long sum;
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> t;
	while(t--){
		cin >> n;
		
		maxi = sum = 0;
		for(i=0; i<n; i++){
			cin >> a;
			maxi = max(maxi, a);
			sum += a;
		}
		
		sum -= maxi;
		cout << (maxi ? max(1LL, maxi-sum) : 0) << '\n';
	}
	
	return 0;
}
