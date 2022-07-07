#include <bits/stdc++.h>

#define MAXN 200010
#define MAX 998244353

using namespace std;

int a[MAXN], b[MAXN];
bool chk[MAXN];
vector<int> m, l;

int main()
{
	int t, n, s, i;
	long long ans;
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> t;
	while(t--){
		for(i=1; i<=n; i++) chk[i] = false;
		m.clear();
		l.clear();
		ans = 1;
		
		cin >> n >> s;
		for(i=0; i<n; i++) cin >> a[i];
		for(i=0; i<n; i++){
			cin >> b[i];
			if(b[i] > 0) chk[b[i]] = true;
		}
		
		for(i=0; i<n; i++){
			if(b[i]!=-1 && a[i]-b[i] > s) break;
		}
		if(i < n){
			cout << "0\n";
			continue;
		}
		
		for(i=1; i<=n; i++){
			if(!chk[i]) m.push_back(i);
		}
		sort(m.begin(), m.end());
		
		for(i=1; i<=n; i++){
			if(b[i] == -1){
				l.push_back(m.end() - lower_bound(m.begin(), m.end(), a[i]-s));
			}
		}
		sort(l.begin(), l.end());
		
		for(i=0; i<l.size(); i++){
			ans = (ans * (l[i]-i)) % MAX;
		}
		
		cout << ans << '\n';
	}
	
	return 0;
}
