#include <bits/stdc++.h>

using namespace std;

set<int> s;

int main()
{
	int a, b, x;
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> a >> b;
	while(a--){
		cin >> x;
		s.insert(x);
	}
	while(b--){
		cin >> x;
		if(s.find(x) == s.end()) s.insert(x);
		else s.erase(x);
	}
	
	cout << s.size();
	
	return 0;
}
