#include <bits/stdc++.h>

using namespace std;

set<string> s;

int main()
{
	int n, m, cnt=0;
	string str;
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n >> m;
	while(n--){
		cin >> str;
		s.insert(str);
	}
	
	while(m--){
		cin >> str;
		if(s.find(str) != s.end()) cnt++;
	}
	
	cout << cnt;
	
	return 0;
}
