#include <iostream>

using namespace std;

bool broken[10];

int make_number(int x)
{
	int cnt=0;
	
	if(x == 0){
		if(broken[0]) return -1;
		return 1;
	}
	
	while(x){
		if(broken[x%10]) return -1;
		x /= 10;
		cnt++;
	}
	
	return cnt;
}

int main()
{
	int n, m, i, x, ans;
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n;
	cin >> m;
	while(m--){
		cin >> x;
		broken[x] = true;
	}
	
	ans = abs(n-100);
	
	for(i=n; i<n+ans; i++){
		x = make_number(i);
		if(x != -1) ans = min(ans, x+(i-n));
	}
	for(i=n; i>=max(n-ans, 0); i--){
		x = make_number(i);
		if(x != -1) ans = min(ans, x+(n-i));
	}
	
	cout << ans;
	
	return 0;
}
