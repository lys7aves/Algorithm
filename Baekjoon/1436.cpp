#include <bits/stdc++.h>

using namespace std;

bool check(int x)
{
	int cnt=0;
	
	while(x){
		if(x%10 == 6) cnt++;
		else cnt = 0;
		
		x /= 10;
		
		if(cnt == 3) return true;
	}
	
	return false;
}

int main()
{
	int n, i;
	
	cin >> n;
	for(i=666; n; i++){
		if(check(i)) n--;
	}
	
	cout << i-1;
	
	return 0;
}
