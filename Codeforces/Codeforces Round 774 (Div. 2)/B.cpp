#include <iostream>
#include <algorithm>

using namespace std;

int a[200010];

int main()
{
	int t, n, i, j;
	long long blue, red;
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> t;
	while(t--){
		cin >> n;
		for(i=0; i<n; i++) cin >> a[i];
		
		sort(a, a+n);
		
		red = a[n-1];
		blue = a[0] + a[1];
		i = 2; j = n-2;
		
		while(i<j && red <= blue){
			blue += a[i]; i++;
			red += a[j]; j--;
		}
		
		if(red > blue) cout << "YES\n";
		else cout << "NO\n";
	}
	
	return 0;
}
