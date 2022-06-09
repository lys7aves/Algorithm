#include <bits/stdc++.h>

#define MIN -10000000

using namespace std;

int sum[100010];

int main()
{
	int n, k, i, x, maxi=MIN;
	
	cin >> n >> k;
	for(i=1; i<=n; i++){
		cin >> x;
		sum[i] = sum[i-1] + x;
		
		if(i >= k) maxi = max(maxi, sum[i]-sum[i-k]);
	}
	
	cout << maxi;
	
	return 0;
}
