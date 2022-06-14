#include <bits/stdc++.h>

using namespace std;

stack<int> s;

int main()
{
	int k, x;
	long long sum=0;
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> k;
	while(k--){
		cin >> x;
		
		if(x) s.push(x);
		else s.pop();
	}
	
	while(!s.empty()){
		sum += s.top();
		s.pop();
	}
	
	cout << sum;
	
	return 0;
}
