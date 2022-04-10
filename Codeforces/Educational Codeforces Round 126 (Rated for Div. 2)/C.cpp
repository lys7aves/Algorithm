#include <bits/stdc++.h>

using namespace std;

int h[300010];
priority_queue<int> que[3];

int main()
{
	int t, n, i, maxi=0, x, y;
	long long ans, ans_;
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> t;
	while(t--){
		cin >> n;
		
		maxi = 0;
		
		for(i=0; i<n; i++){
			cin >> h[i];
			maxi = max(maxi, h[i]);
		}
		
		for(i=0; i<n; i++){
			x = maxi-h[i];
			if(x == 0) continue;
			
			que[x%3].push(x);
		}
		
		ans = 0;
		while((int)que[1].size() - (int)que[2].size() > 1){
			x = que[1].top();
			if(x == 1) break;
			que[1].pop();
			que[2].push(x-2);
			que[2].push(2);
		}
		while((int)que[1].size() - (int)que[2].size() > 1){
			if(que[0].empty()) break;
			x = que[0].top();
			if(x == 3) break;
			que[0].pop();
			que[2].push(x-4);
			que[2].push(2);
			que[2].push(2);
		}
		while((int)que[2].size() - (int)que[1].size() > 1){
			x = que[2].top(); que[2].pop();
			que[1].push(x-1);
			que[1].push(1);
		}
		
		while(!que[1].empty() && !que[2].empty()){
			x = que[1].top(); que[1].pop();
			y = que[2].top(); que[2].pop();
			
			ans += (x+y)/3*2;
		}
		while(!que[0].empty()){
			x = que[0].top(); que[0].pop();
			ans += x/3*2;
		}
		if(!que[1].empty()){
			x = que[1].top(); que[1].pop();
			ans += x/3*2 + 1;
		}
		if(!que[2].empty()){
			x = que[2].top(); que[2].pop();
			ans += x/3*2 + 2;
		}
		while(!que[1].empty()){
			x = que[1].top(); que[1].pop();
			ans += x/3*2 + 2;
		}
		
		ans_ = ans;
		
		while(!que[0].empty());
		while(!que[1].empty());
		while(!que[2].empty());
		
		// ------------------------------------------------
		
		for(i=0; i<n; i++){
			x = maxi-h[i]+1;
			
			que[x%3].push(x);
		}
		
		ans = 0;
		while((int)que[1].size() - (int)que[2].size() > 1){
			x = que[1].top();
			if(x == 1) break;
			que[1].pop();
			que[2].push(x-2);
			que[2].push(2);
		}
		while((int)que[1].size() - (int)que[2].size() > 1){
			if(que[0].empty()) break;
			x = que[0].top();
			if(x == 3) break;
			que[0].pop();
			que[2].push(x-4);
			que[2].push(2);
			que[2].push(2);
		}
		while((int)que[2].size() - (int)que[1].size() > 1){
			x = que[2].top(); que[2].pop();
			que[1].push(x-1);
			que[1].push(1);
		}
		
		while(!que[1].empty() && !que[2].empty()){
			x = que[1].top(); que[1].pop();
			y = que[2].top(); que[2].pop();
			
			ans += (x+y)/3*2;
		}
		while(!que[0].empty()){
			x = que[0].top(); que[0].pop();
			ans += x/3*2;
		}
		if(!que[1].empty()){
			x = que[1].top(); que[1].pop();
			ans += x/3*2 + 1;
		}
		if(!que[2].empty()){
			x = que[2].top(); que[2].pop();
			ans += x/3*2 + 2;
		}
		while(!que[1].empty()){
			x = que[1].top(); que[1].pop();
			ans += x/3*2 + 2;
		}
		
		cout << min(ans_, ans) << '\n';
		
		while(!que[0].empty());
		while(!que[1].empty());
		while(!que[2].empty());
	}
	
	return 0;
}
