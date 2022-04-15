#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n, x, i, cnt=0;
	
	cin >> n;
	while(n--){
		cin >> x;
		
		for(i=2; i<x; i++)
			if(x%i == 0) break;
		
		if(i == x) cnt++;
	}
	
	cout << cnt;
	
	return 0;
}
