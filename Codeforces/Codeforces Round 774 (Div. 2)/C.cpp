#include <iostream>

using namespace std;

int ans;
long long fac[20];

void solve(long long n, int d, int cnt)
{
	if(n < 0) return;
	if(d == 15){
		while(n){
			cnt += n%2;
			n /= 2;
		}
		
		ans = min(ans, cnt);
		
		return;
	}
	
	solve(n, d+1, cnt);
	solve(n-fac[d], d+1, cnt+1);
}

int main()
{
	int t;
	long long n;
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	fac[0] = 1;
	for(int i=1; i<15; i++) fac[i] = fac[i-1]*i;
	
	cin >> t;
	while(t--){
		cin >> n;
		
		ans = 10000000;
		solve(n, 1, 0);
		
		cout << ans << '\n';
	}
	
	return 0;
}
