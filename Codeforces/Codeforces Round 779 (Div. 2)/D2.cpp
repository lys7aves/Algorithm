#include <bits/stdc++.h>

#define MAXN (1<<17)+10

using namespace std;

int a[MAXN];
set<int> s, s_;

int main()
{
	int t, l, r, n, i, j, mul, unpair, x;
	bool flag;
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> t;
	while(t--){
		cin >> l >> r;
		
		n = r-l+1;
		s.clear();
		
		for(i=0; i<n; i++){
			cin >> a[i];
			s.insert(a[i]);
		}
		
		for(mul=1; l%2==0 && r%2==1; l>>=1, r>>=1, mul<<=1){
			s_.clear();
			for(auto it=s.begin(); it!=s.end(); it++) s_.insert((*it) >> 1);
			swap(s, s_);
		}
		
		if(l%2 == 1) unpair = l;
		else unpair = r;
		
		for(auto it=s.begin(); it!=s.end(); it++){
			if(s.find((*it)^1) == s.end()){
				x = (*it) ^ unpair;
				
				flag = true;
				for(auto jt=s.begin(); jt!=s.end(); jt++){
					if(((*jt)^x) < l || ((*jt)^x) > r) flag = false;
				}
				if(flag) break;
			}
		}
		
		cout << x * mul << '\n';
	}
	
	return 0;
}
