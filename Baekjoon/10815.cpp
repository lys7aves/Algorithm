#include <bits/stdc++.h>

using namespace std;

int arr[500010];

int main()
{
	int n, m, i, x;
	int *ptr;
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n;
	for(i=0; i<n; i++){
		cin >> arr[i];
	}
	
	sort(arr, arr+n);
	
	cin >> m;
	for(i=0; i<m; i++){
		cin >> x;
		ptr = lower_bound(arr, arr+n, x);
		
		if(*ptr == x) cout << "1 ";
		else cout << "0 ";
	}
	
	return 0;
}
