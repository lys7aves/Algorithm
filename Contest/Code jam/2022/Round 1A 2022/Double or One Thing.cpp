#include <bits/stdc++.h>

using namespace std;

char min_char[110];

int main()
{
	int T, C, i, j;
	string S;
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> T;
	for(C=1; C<=T; C++){
		cout << "Case #" << C << ": ";
		
		cin >> S;
		
		for(i=0; i<S.size(); i++){
			cout << S[i];
			
			j = i;
			while(S[j] == S[j+1]) j++;
			if(S[j] < S[j+1]) cout << S[j];
		}
		cout << '\n';
	}
	
	return 0;
}
