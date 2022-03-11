#include <iostream>

#define MAXN 200010

using namespace std;

int a[MAXN], b[MAXN];

int main()
{
	int t, n, i;
	int ans_00, ans_nn, ans_0n, ans_n0, a_0, a_n, b_0, b_n;
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> t;
	while(t--){
		cin >> n;
		for(i=0; i<n; i++) cin >> a[i];
		for(i=0; i<n; i++) cin >> b[i];
		
		ans_00 = abs(a[0] - b[0]);
		ans_nn = abs(a[n-1] - b[n-1]);
		ans_0n = abs(a[0] - b[n-1]);
		ans_n0 = abs(a[n-1] - b[0]);
		
		a_0 = abs(a[0] - b[0]);
		a_n = abs(a[n-1] - b[0]);
		b_0 = abs(b[0] - a[0]);
		b_n = abs(b[n-1] - a[0]);
		for(i=1; i<n; i++){
			a_0 = min(a_0, abs(a[0]-b[i]));
			a_n = min(a_n, abs(a[n-1]-b[i]));
			b_0 = min(b_0, abs(b[0]-a[i]));
			b_n = min(b_n, abs(b[n-1]-a[i]));
		}
		
		ans_00 = min(ans_00, a_0 + b_0);
		ans_nn = min(ans_nn, a_n + b_n);
		ans_0n = min(ans_0n, a_0 + b_n);
		ans_n0 = min(ans_n0, a_n + b_0);
		
		cout << min(ans_00+ans_nn, ans_0n+ans_n0) << '\n';
	}
	
	return 0;
}
