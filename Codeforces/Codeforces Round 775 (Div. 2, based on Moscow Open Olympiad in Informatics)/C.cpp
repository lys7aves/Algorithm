#include <iostream>

#define MAXC 100010

using namespace std;

long long cnt[MAXC], minu[MAXC];

int main()
{
	int n, m, i, j;
	long long ans=0;
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n >> m;
	
	int c[n][m];
	for(i=0; i<n; i++){
		for(j=0; j<m; j++){
			cin >> c[i][j];
		}
	}
	
	for(i=0; i<n; i++){
		for(j=0; j<m; j++){
			ans += i*cnt[c[i][j]] - minu[c[i][j]];
			cnt[c[i][j]]++;
			minu[c[i][j]] += i;
		}
	}
	
	for(i=0; i<MAXC; i++) cnt[i] = minu[i] = 0;
	
	for(j=0; j<m; j++){
		for(i=0; i<n; i++){
			ans += j*cnt[c[i][j]] - minu[c[i][j]];
			cnt[c[i][j]]++;
			minu[c[i][j]] += j;
		}
	}
	
	cout << ans;
	
	return 0;
}
