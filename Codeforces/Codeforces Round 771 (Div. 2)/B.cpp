#include <iostream>

using namespace std;

int main()
{
	int t, n, a, i, even, odd;
	bool ans;
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> t;
	while(t--){
		cin >> n;
		
		ans = true;
		even = odd = 0;
		
		for(i=0; i<n; i++){
			cin >> a;
			
			if(a%2){	// odd
				ans &= a >= odd;
				odd = a;
			}
			else{
				ans &= a >= even;
				even = a;
			}
		}
		
		if(ans) cout << "Yes\n";
		else cout << "No\n";
	}
	
	return 0;
}
