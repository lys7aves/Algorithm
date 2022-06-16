#include <bits/stdc++.h>

using namespace std;

int a[100010];
stack<int> s;

int main()
{
	int n, i, num=1;
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n;
	for(i=0; i<n; i++){
		cin >> a[i];
		
		if(!s.empty() && s.top() == a[i]){
			s.pop();
			continue;
		}
		
		while(num <= n){
			s.push(num);
			num++;
			
			if(s.top() == a[i]) break;
		}
		
		if(s.top() == a[i]) s.pop();
		else break;
	}
	
	if(i < n){
		cout << "NO";
		return 0;
	}
	
	num = 1;
	for(i=0; i<n; i++){
		if(!s.empty() && s.top() == a[i]){
			s.pop();
			cout << "-\n";
			continue;
		}
		
		while(num <= n){
			s.push(num);
			num++;
			cout << "+\n";
			
			if(s.top() == a[i]) break;
		}
		
		s.pop();
		cout << "-\n";
	}
	
	return 0;
}
