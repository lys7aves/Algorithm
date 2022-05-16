#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n, w, h, d, x;
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n >> w >> h;
	d = w*w + h*h;
	
	while(n--){
		cin >> x;
		if(x*x <= d) cout << "DA\n";
		else cout << "NE\n";
	}
	
	return 0;
}
