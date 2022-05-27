#include <bits/stdc++.h>

using namespace std;

map<string, int> cnt;

int main()
{
	int t, n, i;
	string name, kind;
	long long ans;
	
	cin >> t;
	while(t--){
		cin >> n;
		
		cnt.clear();
		for(i=0; i<n; i++){
			cin >> name >> kind;
			if(cnt.find(kind) == cnt.end()) cnt[kind] = 0;
			cnt[kind]++;
		}
		
		ans = 1;
		for(auto it:cnt){
			ans *= it.second + 1;
		}
		
		cout << ans-1 << '\n';
	}
	
	return 0;
}
