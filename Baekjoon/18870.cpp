#include <bits/stdc++.h>

using namespace std;

struct Coordinate{
	int x, idx, x_;
};
bool cmp_x(const Coordinate &a, const Coordinate &b){
	return a.x < b.x;
}
bool cmp_idx(const Coordinate &a, const Coordinate &b){
	return a.idx < b.idx;
}

Coordinate coor[1000010];

int main()
{
	int n, i, num=0;
	
	cin >> n;
	for(i=0; i<n; i++){
		cin >> coor[i].x;
		coor[i].idx = i;
	}
	
	sort(coor, coor+n, cmp_x);
	
	for(i=1; i<n; i++){
		if(coor[i].x == coor[i-1].x) coor[i].x_ = coor[i-1].x_;
		else coor[i].x_ = ++ num;
	}
	
	sort(coor, coor+n, cmp_idx);
	
	for(i=0; i<n; i++){
		cout << coor[i].x_ << ' ';
	}
	
	return 0;
}
