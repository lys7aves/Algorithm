#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

long long a[200010];
queue<long long> que;

int main()
{
	int t, n, x, i, ans;
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> t;
	while(t--){
		cin >> n >> x;
		for(i=0; i<n; i++){
			cin >> a[i];
		}
		
		sort(a, a+n);
		
		ans = 0;
		for(i=0; i<n; i++){
			while(!que.empty() && que.front() < a[i]){
				que.pop();
				ans++;
			}
			
			if(que.empty()) que.push(a[i]*x);
			else if(que.front() == a[i]) que.pop();
			else que.push(a[i]*x);
		}
		
		while(!que.empty()){
			que.pop();
			ans++;
		}
		
		cout << ans << '\n';
	}
	
	return 0;
}
