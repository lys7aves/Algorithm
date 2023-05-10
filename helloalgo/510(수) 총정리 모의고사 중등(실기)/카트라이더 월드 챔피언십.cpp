#include <iostream>
#include <algorithm>

#define MAXN 300000

using namespace std;

int arr[MAXN+10], sum[MAXN+10], max1[MAXN+10], max2[MAXN+10];

int main()
{
	int n, i, cnt=0;
	
	cin >> n;
	for(i=1; i<=n; i++){
		cin >> arr[i];
	}
	
	sort(arr+1, arr+n+1);
	for(i=1; i<=n; i++){
		sum[i] = arr[i] + n-i;
		max1[i] = max(max1[i-1], sum[i]);
	}
	for(i=n; i>=1; i--){
		max2[i] = max(max2[i+1], sum[i]);
	}
	
	for(i=1; i<=n; i++){
		if(arr[i]+n >= max1[i-1] && arr[i]+n >= max2[i+1]+1) cnt++;
	}
	
	cout << cnt;
	
	return 0;
}