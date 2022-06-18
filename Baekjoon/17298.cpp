#include <bits/stdc++.h>

using namespace std;

int a[1000010], ans[1000010];
stack<int> s;

int main()
{
	int n, i;
	
	cin >> n;
	for(i=0; i<n; i++) cin >> a[i];
	
	for(i=n-1; i>=0; i--){
		while(!s.empty() && s.top() <= a[i]) s.pop();
		
		if(s.empty()) ans[i] = -1;
		else ans[i] = s.top();
		
		s.push(a[i]);
	}
	
	for(i=0; i<n; i++) cout << ans[i] << ' ';
	
	return 0;
}
