#include <bits/stdc++.h>

using namespace std;

queue<int> que;

int main()
{
	int n, i;
	
	cin >> n;
	for(i=1; i<=n; i++) que.push(i);
	
	while(que.size() > 1){
		que.pop();
		que.push(que.front());
		que.pop();
	}
	
	cout << que.front();
	
	return 0;
}
