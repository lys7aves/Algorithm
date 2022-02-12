#include <iostream>

using namespace std;

int main()
{
	int t, n, i, a, c, cnt;
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> t;
	while(t--){
		cin >> n;
		
		cnt = 0;
		for(i=0; i<n; i++){
			cin >> a;
			
			c = (i-0+1)*(n-i);
			cnt += c;
			if(a == 0) cnt += c;
		}
		
		cout << cnt << '\n';
	}
	
	return 0;
}
