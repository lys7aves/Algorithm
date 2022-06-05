#include <bits/stdc++.h>

using namespace std;

long long w[30][30][30];

int main()
{
	int a, b, c, i, j, k, ans;
	
	for(i=0; i<=20; i++){
		for(j=0; j<=20; j++){
			for(k=0; k<=20; k++){
				if(i*j*k == 0){
					w[i][j][k] = 1;
					continue;
				}
				
				if(i < j && j < k){
					w[i][j][k] = w[i][j][k-1] + w[i][j-1][k-1] - w[i][j-1][k];
				}
				else{
					w[i][j][k] = w[i-1][j][k] + w[i-1][j-1][k] + w[i-1][j][k-1] - w[i-1][j-1][k-1];
				}
			}
		}
	}
	
	while(1){
		cin >> a >> b >> c;
		
		if(a == -1 && b == -1 && c == -1) break;
		
		if(a <= 0 || b <= 0 || c <= 0) ans = 1;
		else if(a > 20 || b > 20 || c > 20) ans = w[20][20][20];
		else ans = w[a][b][c];
		
		cout << "w(" << a << ", " << b << ", " << c << ") = " << ans << '\n';
	}
	
	return 0;
}
