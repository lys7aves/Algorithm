#include <iostream>
#include <algorithm>

using namespace std;

int a[200010];

int main()
{
	int t, n, i, cnt;
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> t;
	while(t--){
		cin >> n;
		for(i=0; i<n; i++) cin >> a[i];
		
		cnt = 0;
		for(i=1; i<n-1; i++){
			if(a[i] > a[i-1] && a[i] > a[i+1]){
				cnt++;
				a[i+1] = max(a[i], a[i+2]);
			}
		}
		
		cout << cnt << '\n';
		for(i=0; i<n; i++) cout << a[i] << ' ';
		cout << '\n';
	}
	
	return 0;
}
