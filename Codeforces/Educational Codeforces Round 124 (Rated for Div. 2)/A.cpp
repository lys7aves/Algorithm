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
		
		cout << (1 << n) - 1 << '\n';
	}
	
	return 0;
}
