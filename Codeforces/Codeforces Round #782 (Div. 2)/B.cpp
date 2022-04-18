#include <bits/stdc++.h>

#define MAXN 200010

using namespace std;

int arr[MAXN], cnt[MAXN];

int main()
{
	int t, n, k, i;
	string str;
	
	cin >> t;
	while(t--){
		cin >> n >> k;
		cin >> str;
		
		for(i=0; i<n; i++){
			arr[i] = str[i]-'0';
			if(k%2 == 1) arr[i] = 1-arr[i];
			
			cnt[i] = 0;
		}
		
		for(i=0; i<n && k>0; i++){
			if(arr[i] == 0){
				cnt[i] = 1;
				arr[i] = 1;
				k--;
			}
		}
		
		cnt[n-1] += k;
		if(k%2 == 1) arr[n-1] = 1-arr[n-1];
		
		for(i=0; i<n; i++) cout << arr[i];
		cout << '\n';
		for(i=0; i<n; i++) cout << cnt[i] << ' ';
		cout << '\n';
	}
	
	return 0;
}
