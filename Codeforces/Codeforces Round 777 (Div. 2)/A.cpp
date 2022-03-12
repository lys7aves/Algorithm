#include <iostream>

using namespace std;

int main()
{
	int t, n, i;
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> t;
	while(t--){
		cin >> n;
		
		if(n%3 == 1){
			cout << 1;
			n--;
		}
		while(n >= 3){
			cout << 21;
			n -= 3;
		}
		if(n == 2) cout << 2;
		cout << '\n';
	}
	
	return 0;
}
