#include <bits/stdc++.h>

#define MAX 32768

using namespace std;

int ans[MAX];
queue<int> que;

int main()
{
	int n, i, a, v, cnt;
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	for(i=0; i<MAX; i++) ans[i] = -1;
	que.push(0);
	que.push(0);
	
	while(!que.empty()){
		v = que.front(); que.pop();
		cnt = que.front(); que.pop();
		
		if(ans[v] != -1) continue;
		ans[v] = cnt;
		
		que.push((v-1+MAX)%MAX);
		que.push(cnt+1);
		if(v%2 == 0){
			que.push(v/2);
			que.push(cnt+1);
			
			que.push((v+MAX)/2);
			que.push(cnt+1);
		}
	}
	
	cin >> n;
	for(i=0; i<n; i++){
		cin >> a;
		cout << ans[a] << ' ';
	}
	
	return 0;
}
