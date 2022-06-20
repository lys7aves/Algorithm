#include <bits/stdc++.h>

using namespace std;

int cnt[10];
queue<int> que;

int main()
{
	int t, n, m, i, c;
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> t;
	while(t--){
		cin >> n >> m;
		
		for(i=1; i<=9; i++) cnt[i] = 0;
		cnt[0] = 1;
		while(!que.empty()) que.pop();
		
		for(i=0; i<n; i++){
			cin >> c;
			
			cnt[c]++;
			que.push(c);
			que.push(i);
		}
		
		for(c=9; c>=0; c--) if(cnt[c]) break;
		
		i = 1;
		while(1){
			if(que.front() == c){
				que.pop();
				cnt[c]--;
				for(; c>=0; c--) if(cnt[c]) break;
				
				if(que.front() == m) break;
				que.pop();
				
				i++;
			}
			else{
				que.push(que.front());
				que.pop();
				que.push(que.front());
				que.pop();
			}
		}
		
		cout << i << '\n';
	}
	
	return 0;
}
