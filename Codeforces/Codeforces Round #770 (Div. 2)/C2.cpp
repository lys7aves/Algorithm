#include <iostream>

using namespace std;

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int t, n, k, i, j;
	
	cin >> t;
	while(t--){
		cin >> n >> k;
		
		if(k != 1 && n%2 == 1) cout << "NO\n";
		else{
			cout << "YES\n";
			for(i=1; i<=n; i++){
				for(j=0; j<k; j++){
					cout << i+j*n << ' ';
				}
				cout << '\n';
			}
		}
	}
	
	return 0;
}
