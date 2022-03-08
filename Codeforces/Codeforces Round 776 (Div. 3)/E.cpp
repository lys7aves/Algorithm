#include <iostream>
#include <algorithm>

#define MAXN 200010

using namespace std;

int n, d;
int a[MAXN], a_[MAXN], rest[MAXN];

int min_rest()
{
	int i, mini=d;
	
	sort(a_+1, a_+n+1);
	for(i=1; i<=n; i++) mini = min(mini, a_[i]-a_[i-1]-1);
	for(i=1; i<=n; i++) a_[i] = a[i];
	
	return mini;
}

int main()
{
	int t, i, min_rest_idx, max_rest_idx, ans;
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> t;
	while(t--){
		cin >> n >> d;
		for(i=1; i<=n; i++) cin >> a[i];
		
		min_rest_idx = max_rest_idx = 1;
		for(i=1; i<=n; i++){
			rest[i] = a[i]-a[i-1]-1;
			if(rest[i] < rest[min_rest_idx]) min_rest_idx = i;
			if(rest[i] > rest[max_rest_idx]) max_rest_idx = i;
		}
		
		for(i=1; i<=n; i++) a_[i] = a[i];
		
		a_[min_rest_idx] = d;
		ans = min_rest();
		
		if(min_rest_idx > 1){
			a_[min_rest_idx-1] = d;
			ans = max(ans, min_rest());
		}
		
		if(min_rest_idx < n){
			a_[min_rest_idx] = (a[min_rest_idx-1] + a[min_rest_idx+1]) / 2;
			ans = max(ans, min_rest());
		}
		
		if(min_rest_idx > 1){
			a_[min_rest_idx-1] = (a[min_rest_idx-2] + a[min_rest_idx]) / 2;
			ans = max(ans, min_rest());
		}
		
		a_[min_rest_idx] = (a[max_rest_idx-1] + a[max_rest_idx]) / 2;
		ans = max(ans, min_rest());
		
		if(min_rest_idx > 1){
			a_[min_rest_idx-1] = (a[max_rest_idx-1] + a[max_rest_idx]) / 2;
			ans = max(ans, min_rest());
		}
		
		cout << ans << '\n';
	}
	
	return 0;
}
