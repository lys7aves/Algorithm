#include <bits/stdc++.h>

using namespace std;

int sum(int x)
{
	int res=x;
	
	while(x){
		res += x%10;
		x /= 10;
	}
	
	return res;
}

int main()
{
	int n, i;
	
	cin >> n;
	for(i=1; i<n; i++){
		if(sum(i) == n) break;
	}
	
	if(i == n) cout << 0;
	else cout << i;
	
	return 0;
}
