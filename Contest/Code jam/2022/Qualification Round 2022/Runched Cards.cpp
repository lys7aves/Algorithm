#include <bits/stdc++.h>

using namespace std;

int main()
{
	int T, C, r, c, i, j;
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> T;
	for(C=1; C<=T; C++){
		cout << "Case #" << C << ":\n";
		
		cin >> r >> c;
		
		cout << "..+";
		for(j=1; j<c; j++) cout << "-+";
		cout <<'\n';
		
		for(i=0; i<r; i++){
			if(i == 0) cout << ".";
			else cout << "|";
			for(j=0; j<c; j++) cout << ".|";
			cout << '\n';
			
			cout << "+";
			for(j=0; j<c; j++) cout << "-+";
			cout << '\n';
		}
	}
	
	return 0;
}
