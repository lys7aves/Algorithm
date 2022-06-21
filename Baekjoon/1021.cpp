#include <bits/stdc++.h>

using namespace std;

queue<int> que;

int main()
{
	int n, m, i, x, p, ans=0;
	
	cin >> n;
	for(i=1; i<=n; i++) que.push(i);
	
	cin >> m;
	for(i=0; i<m; i++){
		cin >> x;
		
		p = 0;
		while(que.front() != x){
			que.push(que.front());
			que.pop();
			p++;
		}
		que.pop();
		
		ans += min(p, n-i-p);
	}
	
	cout << ans;
	
	return 0;
}
