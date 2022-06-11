#include <bits/stdc++.h>

using namespace std;

int sum['z'+1][200010];

int main()
{
	string s;
	int i, j, q, l, r;
	char a;
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> s;
	sum[s[0]][0] = 1;
	for(i=1; i<s.size(); i++){
		for(j='a'; j<='z'; j++) sum[j][i] = sum[j][i-1];
		sum[s[i]][i]++;
	}
	
	cin >> q;
	while(q--){
		cin >> a >> l >> r;
		cout << sum[a][r] - (l==0 ? 0 : sum[a][l-1]) << '\n';
	}
	
	return 0;
}
