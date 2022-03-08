#include <iostream>

using namespace std;

int a[2010], tmp[2010], ans[2010];

int main()
{
	int t, n, i, j, idx;
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> t;
	while(t--){
		cin >> n;
		for(i=0; i<n; i++){
			cin >> a[i];
		}
		
		for(j=n; j>=1; j--){
			for(i=0; i<j; i++){
				if(a[i] == j) idx = i;
			}
			
			ans[j] = (idx+1)%j;
			
			for(i=0; i<j; i++) tmp[i] = a[(i+idx+1)%j];
			for(i=0; i<j; i++) a[i] = tmp[i];
		}
		
		for(i=1; i<=n; i++) cout << ans[i] << ' ';
		cout << '\n';
		
	}
	
	return 0;
}
