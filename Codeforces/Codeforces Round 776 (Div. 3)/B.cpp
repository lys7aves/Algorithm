#include <iostream>

using namespace std;

int main()
{
	int t, l, r, a, ans, x;
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> t;
	while(t--){
		cin >> l >> r >> a;
		
		ans = (r/a) + (r%a);
		
		x = r/a*a - 1;
		if(l <= x) ans = max(ans, (x/a) + (x%a));
		
		cout << ans << '\n';
	}
	
	return 0;
}
