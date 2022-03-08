#include <iostream>
#include <algorithm>

using namespace std;

struct PointInfo{
	int x, w, idx;
	bool use;
};
bool w_cmp(const PointInfo &a, const PointInfo &b){
	return a.w < b.w;
}
bool x_cmp(const PointInfo &a, const PointInfo &b){
	return a.x < b.x;
}

PointInfo points[200010];

int main()
{
	int t, n, m, i, l, r, sum;
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> t;
	while(t--){
		cin >> n >> m;
		for(i=0; i<m; i++){
			cin >> points[i].x >> points[i].w;
			points[i].idx = i+1;
		}
		
		sort(points, points+m, w_cmp);
		
		sum = 0;
		for(i=0; i<2*n; i++){
			sum += points[i].w;
			points[i].use = true;
		}
		for(; i<m; i++) points[i].use = false;
		
		sort(points, points+m, x_cmp);
		
		cout << sum << '\n';
		l = 0; r = m-1;
		for(i=0; i<n; i++){
			while(!points[l].use) l++;
			while(!points[r].use) r--;
			
			cout << points[l].idx << ' ' << points[r].idx << '\n';
			l++;
			r--;
		}
		cout << '\n';
	}
	
	return 0;
}
