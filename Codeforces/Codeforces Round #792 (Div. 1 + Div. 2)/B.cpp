#include <bits/stdc++.h>

using namespace std;

struct Node{
	int num, idx, ans;
};
bool cmp_num(const Node &x, const Node &y){
	return x.num < y.num;
}
bool cmp_idx(const Node &x, const Node &y){
	return x.idx < y.idx;
}

Node arr[3];

void solve()
{
	arr[2].ans = arr[2].num;
	arr[1].ans = (arr[1].num>arr[0].num ? arr[2].ans : 0) + arr[1].num;
	arr[0].ans = arr[1].ans + arr[0].num;
}

int main()
{
	int t, i;
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	for(i=0; i<3; i++) arr[i].idx = i;
	
	cin >> t;
	while(t--){
		for(i=0; i<3; i++) cin >> arr[i].num;
		
		sort(arr, arr+3, cmp_num);
		
		solve();
		
		sort(arr, arr+3, cmp_idx);
		
		for(i=0; i<3; i++) cout << arr[i].ans << ' ';
		cout << '\n';
	}
	return 0;
}
