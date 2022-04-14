#include <bits/stdc++.h>

using namespace std;

int main()
{
	string a, b, ans;
	int carry=0, x, i;
	
	cin >> a >> b;
	
	for(i=0; i<a.size() || i<b.size(); i++){
		x = carry;
		
		if(i < a.size()) x += a[a.size()-i-1] - '0';
		if(i < b.size()) x += b[b.size()-i-1] - '0';
		
		ans += (char)((x%10)+'0');
		carry = x/10;
	}
	
	if(carry > 0) ans += (char)(carry+'0');
	
	for(i=ans.size()-1; i>=0; i--) cout << ans[i];
	
	return 0;
}
