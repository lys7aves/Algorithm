#include <bits/stdc++.h>

using namespace std;

int main()
{
	int t, n, i, a, cnt;
	bool flag;
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> t;
	while(t--){
		cin >> n;
		
		cnt = flag = 0;
		for(i=0; i<n; i++){
			cin >> a;
			if(a == 0){
				cnt += flag;
				flag = 0;
			}
			else{
				flag = true;
			}
		}
		
		cout << min(2, cnt+flag) << '\n';
	}
	
	return 0;
}
