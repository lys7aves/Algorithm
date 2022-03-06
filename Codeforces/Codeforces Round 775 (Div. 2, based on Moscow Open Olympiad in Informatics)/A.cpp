#include <iostream>

using namespace std;

int main()
{
	int t, n, i, a, ans, fir, las;
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> t;
	while(t--){
		cin >> n;
		
		fir = 0;
		las = -2;
		for(i=0; i<n; i++){
			cin >> a;
			
			if(a == 0){
				if(!fir) fir = i;
				las = i;
			}
		}
		
		 cout << las-fir+2 << '\n';
	}
	
	return 0;
}
