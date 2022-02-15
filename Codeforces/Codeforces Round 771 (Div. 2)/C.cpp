#include <iostream>

using namespace std;

int idx[100010];

int main()
{
	int t, n, i, p, max_idx, cnt;
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> t;
	while(t--){
		cin >> n;
		for(i=1; i<=n; i++){
			cin >> p;
			idx[p] = i;
		}
		
		max_idx = cnt = 0;
		for(i=1; i<=n; i++){
			max_idx = max(max_idx, idx[i]);
			
			if(max_idx == i) cnt++;
		}
		
		cout << cnt << '\n';
	}
	
	return 0;
}
