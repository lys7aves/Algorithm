#include <iostream>

using namespace std;

int a[100000];

int main()
{
	int t, n, i;
	long long cnt;
	bool all_one;
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> t;
	while(t--){
		cin >> n;
		
		cnt = 0;
		all_one = true;
		for(i=0; i<n; i++){
			cin >> a[i];
			
			if(i == 0 || i == n-1) continue;
			
			cnt += (a[i]+1)/2;
			all_one &= a[i] == 1;
		}
		
		if(all_one || (n==3 && a[1]%2==1)) cout << -1 << '\n';
		else cout << cnt << '\n';
	}
	
	return 0;
}
