#include <bits/stdc++.h>

#define MAX_COLOR 1000000

using namespace std;

int color[3][4], mini[4];

int main()
{
	int T, C, i, j, sum;
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> T;
	for(C=1; C<=T; C++){
		cout << "Case #" << C << ": ";
		
		for(j=0; j<4; j++) mini[j] = MAX_COLOR;
		for(i=0; i<3; i++){
			for(j=0; j<4; j++){
				cin >> color[i][j];
				mini[j] = min(mini[j], color[i][j]);
			}
		}
		
		sum = 0;
		for(j=0; j<4; j++) sum += mini[j];
		
		if(sum < MAX_COLOR) cout << "IMPOSSIBLE\n";
		else{
			sum = 0;
			for(j=0; j<4; j++){
				if(sum + mini[j] > MAX_COLOR){
					cout << MAX_COLOR - sum << ' ';
					sum = MAX_COLOR;
				}
				else{
					cout << mini[j] << ' ';
					sum += mini[j];
				}
			}
			cout << '\n';
		}
	}
	
	return 0;
}
