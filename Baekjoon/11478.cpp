#include <bits/stdc++.h>

using namespace std;

set<string> s;

int main()
{
	int i, j;
	string S, str;
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> S;
	for(i=0; i<S.size(); i++){
		for(j=0; j<S.size()-i; j++){
			str = S.substr(i, j+1);
			s.insert(str);
		}
	}
	
	cout << s.size();
	
	return 0;
}
