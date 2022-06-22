#include <bits/stdc++.h>

using namespace std;

int main()
{
	int T, C, i, j;
	string I, P;
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> T;
	for(C=1; C<=T; C++){
		cin >> I >> P;
		
		i = j = 0;
		for(i=0; i<I.size(); i++){
			while(j < P.size() && I[i] != P[j]) j++;
			j++;
		}
		
		cout << "Case #" << C << ": ";
		if(j <= P.size()) cout << P.size() - I.size() << '\n';
		else cout << "IMPOSSIBLE\n";
	}

	return 0;
}
