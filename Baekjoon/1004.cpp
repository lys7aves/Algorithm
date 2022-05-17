#include <bits/stdc++.h>

using namespace std;

int main()
{
	int t, x1, y1, x2, y2, n, x, y, r, cnt, dx, dy;
	long long d1, d2;
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> t;
	while(t--){
		cin >> x1 >> y1 >> x2 >> y2;
		cin >> n;
		
		cnt = 0;
		while(n--){
			cin >> x >> y >> r;
			
			dx = x - x1;
			dy = y - y1;
			d1 = dx*dx + dy*dy - r*r;
			
			dx = x - x2;
			dy = y - y2;
			d2 = dx*dx + dy*dy - r*r;
			
			if(d1*d2 < 0) cnt++;
		}
		
		cout << cnt << '\n';
	}
	
	return 0;
}
