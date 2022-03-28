#include <bits/stdc++.h>

using namespace std;

bool chk['z'+1];

int main()
{
	int t, i, idx;
	string str;
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> t;
	while(t--){
		cin >> str;
		
		for(i='a'; i<='z'; i++) chk[i] = false;
		for(i=str.size()-1; i>=0; i--){
			if(!chk[str[i]]) idx = i;
			chk[str[i]] = true;
		}
		
		for(i=idx; i<str.size(); i++) cout << str[i];
		cout << '\n';
		
	}
	
	return 0;
}
