#include <bits/stdc++.h>

using namespace std;

int main()
{
	int w, h, x1, y1, x2, y2, r, p, x, y, dx, dy, cnt=0;
	
	cin >> w >> h >> x >> y >> p;
	
	r = h/2;
	x1 = x;
	y1 = y + r;
	x2 = x + w;
	y2 = y1;
	
	while(p--){
		cin >> x >> y;
		
		dx = x - x1;
		dy = y - y1;
		if(dx*dx + dy*dy <= r*r){
			cnt++;
			continue;
		}
		
		dx = x - x2;
		dy = y - y2;
		if(dx*dx + dy*dy <= r*r){
			cnt++;
			continue;
		}
		
		if(x1 <= x && x <= x2 && abs(y1-y) <= r) cnt++;
	}
	
	cout << cnt;
	
	return 0;
}
