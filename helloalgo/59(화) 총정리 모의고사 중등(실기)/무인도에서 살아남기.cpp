#include <iostream>

using namespace std;

int num[10000], sum[10000];

int main()
{
	int n, i, j, x, maxi=0, cnt=0;
	
	cin >> n;
	for(i=0; i<n; i++){
		cin >> x;
		num[x]++;
	}
	
	for(i=2; i<=4000; i++){
		for(j=1; j<=(i-1)/2; j++){
			sum[i] += min(num[j],num[i-j]);
		}
		if(i%2 == 0) sum[i] += num[i/2] / 2;
		
		if(maxi < sum[i]){
			maxi = sum[i];
			cnt = 1;
		}
		else if(maxi == sum[i]) cnt++;
	}
	
	cout << maxi << ' ' << cnt;
	
	return 0;
}