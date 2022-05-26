#include <bits/stdc++.h>

using namespace std;

long long C[31][31];

int main()
{
	int t, n, m, i, j;
	long long ans;
	
	for(i=0; i<=30; i++){
		C[i][0] = 1;
		for(j=1; j<=i; j++) C[i][j] = C[i-1][j-1] + C[i-1][j];
	}
	
	cin >> t;
	while(t--){
		cin >> n >> m;
		
		cout << C[m][n] << '\n';
	}
	
	return 0;
}
