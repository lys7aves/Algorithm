#include <iostream>
#include <algorithm>
#include <stdio.h>

#define MAXN 200010

using namespace std;

struct PointInfo{
	int x, y, idx, l, r;
	int x_, y_;
	bool flag;
};
bool xy_cmp(const PointInfo &a, const PointInfo &b){
	if(a.x != b.x) return a.x < b.x;
	else return a.y < b.y;
}
bool yx_cmp(const PointInfo &a, const PointInfo &b){
	if(a.y != b.y) return a.y < b.y;
	else return a.x < b.x;
}
bool idx_cmp(const PointInfo &a, const PointInfo &b){
	return a.idx < b.idx;
}

PointInfo points[MAXN];

int main()
{
	int n, i, j, len, len_u, len_d;
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n;
	for(i=1; i<=n; i++){
		cin >> points[i].x >> points[i].y;
		points[i].idx = i;
	}
	points[0].x = points[0].y = points[n+1].x = points[n+1].y = -1;
	
	sort(points+1, points+n+1, yx_cmp);
	
	for(i=1; i<=n; i++){
		if(points[i].y != points[i-1].y || points[i].x != points[i-1].x+1) points[i].l = 0;
		else points[i].l = points[i-1].l+1;
	}
	for(i=n; i>=1; i--){
		if(points[i].y != points[i+1].y || points[i].x != points[i+1].x-1) points[i].r = 0;
		else points[i].r = points[i+1].r+1;
	}
	
	sort(points+1, points+n+1, xy_cmp);
	
	for(i=1; i<=n; i++){
		len = min(points[i].l, points[i].r);
		for(j=0; j<=len; j++){
			if(points[i+j].x != points[i].x || points[i+j].y != points[i].y+j){
				points[i].x_ = points[i].x;
				points[i].y_ = points[i].y+j;
				points[i].flag = true;
				break;
			}
			if(points[i-j].x != points[i].x || points[i-j].y != points[i].y-j){
				points[i].x_ = points[i].x;
				points[i].y_ = points[i].y-j;
				points[i].flag = true;
				break;
			}
			
			len = min(len, j+min(points[i+j].l, points[i+j].r));
			len = min(len, j+min(points[i-j].l, points[i-j].r));
		}
		
		if(points[i].flag) continue;
		
		for(j=0; true; j++){
			len_u = j+min(points[i+j].l, points[i+j].r);
			len_d = j+min(points[i-j].l, points[i-j].r);
			
			if(len < len_u && len < len_d) continue;
			
			if(len == len_u){
				if(len == j+points[i+j].l){
					points[i].x_ = points[i].x - points[i+j].l - 1;
					points[i].y_ = points[i].y + j;
					break;
				}
				if(len == j+points[i+j].r){
					points[i].x_ = points[i].x + points[i+j].r + 1;
					points[i].y_ = points[i].y + j;
					break;
				}
			}
			if(len == len_d){
				if(len == j+points[i-j].l){
					points[i].x_ = points[i].x - points[i-j].l - 1;
					points[i].y_ = points[i].y - j;
					break;
				}
				if(len == j+points[i-j].r){
					points[i].x_ = points[i].x + points[i-j].r + 1;
					points[i].y_ = points[i].y - j;
					break;
				}
			}
		}
	}
	
	sort(points+1, points+n+1, idx_cmp);
	
	for(i=1; i<=n; i++){
		cout << points[i].x_ << ' ' << points[i].y_ << '\n';
	}
	
	
	return 0;
}
