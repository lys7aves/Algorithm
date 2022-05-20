#include <bits/stdc++.h>

using namespace std;

int arr[100010];
vector<int> brr;

int main()
{
	int t, n, k, i, mex, cnt;
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> t;
	while(t--){
		cin >> n >> k;
		for(i=0; i<n; i++){
			cin >> arr[i];
		}
		
		sort(arr, arr+n);
		
		mex = cnt = 0;
		for(i=0; i<n; i++){
			if(arr[i] < mex) continue;
			else if(arr[i] == mex) mex++;
			else{
				if(cnt == k) break;
				cnt++;
				mex++;
				i--;
			}
		}
		
		cnt = 0;
		brr.clear();
		for(; i<n; i++){
			if(i == 0 || arr[i] != arr[i-1]){
				brr.push_back(cnt);
				cnt = 1;
			}
			else cnt++;
		}
		brr.push_back(cnt);
		
		sort(brr.begin(), brr.end());
		
		for(i=1; i<brr.size(); i++){
			if(k < brr[i]) break;
			k -= brr[i];
		}
		
		cout << brr.size() - i << '\n';
	}
	
	return 0;
}
