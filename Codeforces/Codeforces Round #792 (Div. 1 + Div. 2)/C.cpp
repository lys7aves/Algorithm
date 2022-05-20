#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<int> arr[200010];
set<int> s;

bool check_swap(int x, int y)
{
	int i, j, tmp;
	
	for(i=0; i<n; i++){
		tmp = arr[i][x];
		arr[i][x] = arr[i][y];
		arr[i][y] = tmp;
		
		for(j=1; j<m; j++){
			if(arr[i][j] < arr[i][j-1]) return false;
		}
	}
	
	return true;
}

int main()
{
	int t, i, j, x;
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> t;
	while(t--){
		cin >> n >> m;
		for(i=0; i<n; i++){
			arr[i].clear();
			for(j=0; j<m; j++){
				cin >> x;
				arr[i].push_back(x);
			}
		}
		
		s.clear();
		for(i=0; i<n; i++){
			for(j=1; j<m; j++){
				if(arr[i][j] < arr[i][j-1]) s.insert(j);
			}
		}
		
		if(s.size() > 2){
			cout << "-1\n";
			continue;
		}
		if(s.size() == 0){
			cout << "1 1\n";
			continue;
		}
		if(s.size() == 2){
			i = *s.begin() - 1;
			j = *s.rbegin();
		}
		if(s.size() == 1){
			i = *s.begin() - 1;
			j = *s.begin();
		}
		
		if(check_swap(i, j)) cout << i+1 << ' ' << j+1 << '\n';
		else cout << "-1\n";
	}
	
	return 0;
}
