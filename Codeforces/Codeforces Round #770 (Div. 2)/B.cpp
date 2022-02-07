#include <iostream>

using namespace std;

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int t, n, x, a, i;
	long long y;
	
	cin >> t;
	while(t--){
		cin >> n >> x >> y;
		
		for(i=0; i<n; i++){
			cin >> a;
			x ^= a;
		}
		
		if((x&1) == (y&1)) cout << "Alice\n";
		else cout << "Bob\n";
	}
	
	return 0;
}
