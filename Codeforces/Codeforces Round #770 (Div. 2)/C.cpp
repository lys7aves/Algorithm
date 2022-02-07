#include <iostream>

using namespace std;

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int t, n, k, i, j;
	int a[2];
	
	cin >> t;
	while(t--){
		cin >> n >> k;
		
		if(k != 1 && n%2 == 1) cout << "NO\n";
		else{
			cout << "YES\n";
			
			a[0] = 1;
			a[1] = 2;
			for(i=0; i<n; i++){
				for(j=0; j<k; j++){
					cout << a[i%2] << ' ';
					a[i%2] += 2;
				}
				cout << '\n';
			}
		}
	}
	
	return 0;
}
