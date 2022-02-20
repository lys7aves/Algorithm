#include <iostream>

using namespace std;

int main()
{
	int t, n, a, ans;
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> t;
	while(t--){
		cin >> n;
		
		ans = 0;
		while(n--){
			cin >> a;
			ans |= a;
		}
		
		cout << ans << '\n';
	}
	
	return 0;
}
