#include <bits/stdc++.h>

using namespace std;

int dp[510];
pair<int, int> arr[110];

int main()
{
	int n, i, j, x;
	
	cin >> n;
	for(i=0; i<n; i++) cin >> arr[i].first >> arr[i].second;
	
	sort(arr, arr+n);
	
	for(i=0; i<n; i++){
		x = arr[i].second;
		
		for(j=0; j<x; j++){
			dp[x] = max(dp[x], dp[j]);
		}
		dp[x]++;
	}
	
	x = 0;
	for(i=0; i<=500; i++){
		x = max(x, dp[i]);
	}
	
	cout << n-x;
	
	return 0;
}
