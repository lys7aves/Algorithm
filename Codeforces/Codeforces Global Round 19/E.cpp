#include <iostream>
#include <unordered_set>
#include <vector>
#include <queue>
#include <algorithm>

#define MAXN 300010
#define pii pair<int,int>
#define pi5 pair<int, pair<int, pair<int, pair<int, int> > > >
#define i1 first
#define i2 second.first
#define i3 second.second.first
#define i4 second.second.second.first
#define i5 second.second.second.second

using namespace std;

int a[MAXN];
unordered_set<long long> s;
vector<int> cnt_num[MAXN], cnt_vec;
priority_queue<pi5> que;

int main()
{
	int t, n, m, i, j, x, y, cnt, f;
	int cnt1, cnt1i, cnt2, cnt2i;
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> t;
	while(t--){
		cin >> n >> m;
		for(i=1; i<=n; i++){
			cin >> a[i];
		}
		for(i=0; i<m; i++){
			cin >> x >> y;
			s.insert(x*MAXN+y);
			s.insert(y*MAXN+x);
		}
		
		sort(a+1, a+n+1);
		
		cnt = 0;
		for(i=n; i>=1; i--){
			cnt++;
			if(a[i] != a[i-1]){
				cnt_num[cnt].push_back(a[i]);
				if(cnt_num[cnt].size() == 1) cnt_vec.push_back(cnt);
				cnt = 0;
			}
		}
		
		for(i=0; i<cnt_vec.size(); i++){
			if(cnt_num[cnt_vec[i]].size() >= 2){
				f = cnt_vec[i]*2 * (cnt_num[cnt_vec[i]][0] + cnt_num[cnt_vec[i]][1]);
				que.push({f, {cnt_vec[i], {0, {cnt_vec[i], 1}}}});
			}
			for(j=i+1; j<cnt_vec.size(); j++){
				if(i == j) continue;
				
				f = (cnt_vec[i]+cnt_vec[j]) * (cnt_num[cnt_vec[i]][0] + cnt_num[cnt_vec[j]][0]);
				que.push({f, {cnt_vec[i], {0, {cnt_vec[j], 0}}}});
			}
		}
		
		while(!que.empty()){
			f = que.top().i1;
			cnt1 = que.top().i2;
			cnt1i = que.top().i3;
			cnt2 = que.top().i4;
			cnt2i = que.top().i5;
			que.pop();
			
			x = cnt_num[cnt1][cnt1i];
			y = cnt_num[cnt2][cnt2i];
			
			if(s.find(x*MAXN+y) == s.end()) break;
			
			if(cnt1 == cnt2){
				if(cnt_num[cnt1].size()-1 == cnt2i) continue;
				f = cnt1*2 * (cnt_num[cnt1][cnt1i+1] + cnt_num[cnt1][cnt1i+2]);
				que.push({f, {cnt1, {cnt1+1, {cnt1, cnt1+2}}}});
			}
			else{
				if(cnt_num[cnt1].size()-1 != cnt1i){
					f = (cnt1 + cnt2) * (cnt_num[cnt1][cnt1i+1] + cnt_num[cnt2][cnt2i]);
					que.push({f, {cnt1, {cnt1i+1, {cnt2, cnt2i}}}});
				}
				if(cnt_num[cnt2].size()-1 != cnt2i){
					f = (cnt1 + cnt2) * (cnt_num[cnt1][cnt1i] + cnt_num[cnt2][cnt2i+1]);
					que.push({f, {cnt1, {cnt1i, {cnt2, cnt2i+1}}}});
				}
			}
		}
		
		cout << f << '\n';
		
		
		// reset
		for(i=0; i<cnt_vec.size(); i++){
			cnt_num[cnt_vec[i]].clear();
		}
		cnt_vec.clear();
		while(!que.empty()) que.pop();
	}
	
	return 0;
}
