#include <bits/stdc++.h>

using namespace std;

int main()
{
	int t, h, w, n;
	
	cin >> t;
	while(t--){
		cin >> h >> w >> n;
		
		printf("%d%02d\n", (n-1)%h+1, (n-1)/h+1);
	}
	
	return 0;
}
