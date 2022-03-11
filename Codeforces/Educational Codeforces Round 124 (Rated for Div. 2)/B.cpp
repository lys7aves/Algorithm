#include <iostream>

using namespace std;

int main()
{
	int t, n, a, i;
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> t;
	while(t--){
		cin >> n;
		
		if(n > 19){
			cout << "NO\n";
			continue;
		}
		
		cout << "YES\n";
		
		a = 1;
		for(i=0; i<n; i++){
			cout << a << ' ';
			a *= 3;
		}
		cout << '\n';
	}
	
	return 0;
}
