#include <bits/stdc++.h>

using namespace std;

int board[100][100];

int main()
{
	int n, m, i, j, ii, jj, w, b, maxi=0;
	
	cin >> n >> m;
	for(i=0; i<n; i++){
		for(j=0; j<m; j++){
			scanf(" %c", &board[i][j]);
		}
	}
	
	for(i=0; i<n-7; i++){
		for(j=0; j<m-7; j++){
			w = b = 0;
			for(ii=0; ii<8; ii++){
				for(jj=0; jj<8; jj++){
					if((board[i+ii][j+jj] == 'W') ^ ((ii+jj)%2)) w++;
					else b++;
				}
			}
			maxi = max(maxi, max(w, b));
		}
	}
	
	cout << 64-maxi;
	
	return 0;
}
