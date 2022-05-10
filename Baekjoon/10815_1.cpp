#include <bits/stdc++.h>

using namespace std;

set<int> s;

int main()
{
	int n, m, x;
	
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
	cin >> n;
	while(n--){
		cin >> x;
		s.insert(x);
	}
	
	cin >> m;
	while(m--){
		cin >> x;
		if(s.find(x) != s.end()) cout << "1 ";
		else cout << "0 ";
	}
	
	return 0;
}
