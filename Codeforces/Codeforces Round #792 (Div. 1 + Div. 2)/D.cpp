#include <bits/stdc++.h>

using namespace std;

struct Node{
	int x, idx;
	bool flag;
};
bool cmp_point(const Node &a, const Node &b){
	return a.x+a.idx > b.x+b.idx;
}
bool cmp_idx(const Node &a, const Node &b){
	return a.idx < b.idx;
}

int start;
Node arr[200010];
int tree[800010];

void t_clear(int n){
	start = 1;
	while(start < n) start *= 2;
	
	for(int i=0; i<start*2; i++) tree[i] = 0;
}

void t_insert(int i){
	for(i+=start; i; i/=2) tree[i]++;
}

int t_cnt(int i){
	int l, r, cnt=0;
	
	l = start + i;
	r = 2*start-1;
	
	while(l <= r){
		if(l%2 == 1){
			cnt += tree[l];
			l++;
		}
		
		l /= 2;
		r /= 2;
	}
	
	return cnt;
}

int main()
{
	int t, n, k, i, cnt;
	long long ans;
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> t;
	while(t--){
		cin >> n >> k;
		for(i=0; i<n; i++){
			cin >> arr[i].x;
			arr[i].idx = i;
			arr[i].flag = true;
		}
		
		sort(arr, arr+n, cmp_point);
		
		t_clear(n);
		for(i=0; i<k; i++){
			cnt = t_cnt(arr[i].idx);
			
			if(arr[i].x - (n-arr[i].idx-1) + cnt > 0){
				arr[i].flag = false;
				t_insert(arr[i].idx);
			}
			else break;
		}
		
		sort(arr, arr+n, cmp_idx);
		
		ans = cnt = 0;
		for(i=0; i<n; i++){
			if(arr[i].flag) ans += arr[i].x + cnt;
			else cnt++;
		}
		
		cout << ans << '\n';
	}
	
	return 0;
}
