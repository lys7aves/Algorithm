#include <bits/stdc++.h>

using namespace std;

int card[110];

int main()
{
	int n, m, i, j, k, sum, maxi=0;
	
	cin >> n >> m;
	for(i=0; i<n; i++) cin >> card[i];
	
	for(i=0; i<n; i++){
		for(j=i+1; j<n; j++){
			for(k=j+1; k<n; k++){
				sum = card[i] + card[j] + card[k];
				if(sum > m) continue;
				
				maxi = max(maxi, sum);
			}
		}
	}
	
	cout << maxi;
	
	return 0;
}
