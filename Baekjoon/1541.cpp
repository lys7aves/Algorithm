#include <bits/stdc++.h>

using namespace std;

int main()
{
	int num, ans;
	char c;
	bool flag=false;
	
	cin >> ans;
	while(!cin.eof()){
		num = 0;
		cin >> c >> num;
		
		if(c == '-') flag = true;
		
		if(flag) ans -= num;
		else ans += num;
	}
	
	cout << ans;
	
	return 0;
}
