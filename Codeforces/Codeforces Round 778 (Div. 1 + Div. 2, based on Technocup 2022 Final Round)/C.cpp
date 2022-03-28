#include <bits/stdc++.h>
#include <queue>

using namespace std;

priority_queue<long long> que, a;

int main()
{
	int t, n, i;
	long long x, sum;
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> t;
	while(t--){
		cin >> n;
		
		sum = 0;
		for(i=0; i<n; i++){
			cin >> x;
			a.push(x);
			sum += x;
		}
		
		que.push(sum);
		for(i=0; i<2*n-1; i++){
			x = que.top(); que.pop();
			
			if(x == a.top()){
				a.pop();
			}
			else{
				que.push(x/2);
				que.push((x+1)/2);
			}
		}
		
		if(a.empty()) cout << "YES\n";
		else cout << "NO\n";
		
		while(!que.empty()) que.pop();
		while(!a.empty()) a.pop();
	}
	
	return 0;
}
