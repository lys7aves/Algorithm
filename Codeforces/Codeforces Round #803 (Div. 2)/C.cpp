#include <bits/stdc++.h>

using namespace std;

vector<int> pos, neg, num;

int main()
{
	int t, n, i, j, k, l, a, cnt0;
	bool flag;
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> t;
	while(t--){
		pos.clear();
		neg.clear();
		num.clear();
		cnt0 = 0;
		
		cin >> n;
		for(i=0; i<n; i++){
			cin >> a;
			if(a > 0) pos.push_back(a);
			if(a < 0) neg.push_back(a);
			if(a == 0) cnt0++;
		}
		
		if(pos.size() > 2 || neg.size() > 2){
			cout << "NO\n";
			continue;
		}
		
		for(auto x: pos) num.push_back(x);
		for(auto x: neg) num.push_back(x);
		for(i=0; i<min(2, cnt0); i++) num.push_back(0);
		
		flag = true;
		for(i=0; i<num.size(); i++){
			for(j=i+1; j<num.size(); j++){
				for(k=j+1; k<num.size(); k++){
					for(l=0; l<num.size(); l++){
						if(num[i] + num[j] + num[k] == num[l]) break;
					}
					if(l == num.size()) flag = false;
				}
			}
		}
		
		if(flag) cout << "YES\n";
		else cout << "NO\n";
	}
	
	return 0;
}
