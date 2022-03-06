#include <iostream>

#define MAXC 1000010

using namespace std;

int a[MAXC], sum[MAXC];
bool chk[MAXC];

int main()
{
	int t, n, c, i, j;
	bool ans;
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> t;
	while(t--){
		cin >> n >> c;
		
		for(i=1; i<=c; i++) chk[i] = false;
		
		for(i=0; i<n; i++){
			cin >> a[i];
			chk[a[i]] = true;
		}
		
		for(i=1; i<=c; i++){
			sum[i] = sum[i-1] + chk[i];
		}
		
		ans = true;
		for(i=0; i<n; i++){
			for(j=1; j*j <= n; j++){
				if(chk[j]){
					if(chk[n/j] == false){
						ans = false;
						break;
					}
				}
				
				int l = n/j;
				int r = n/(j-1)-1;
				
				if(sum[r]-sum[l-1]){
					if(chk[j] == false){
						ans = false;
						break;
					}
				}
			}
			if(!ans) break;
		}
		
		if(ans) cout << "YES\n";
		else cout << "NO\n";
	}
	
	return 0;
}
