#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n, i, cnt=0, ans=0;
	char c;
	string str;
	
	cin >> n;
	cin >> str;
	
	c = 'A';
	for(i=str.size()-1; i>=0; i--){
		if(str[i] == c){
			if(cnt == 0);
			else if(cnt == 1){
				ans++;
				cnt = 0;
			}
			else{
				ans++;
				c = 'A' + 'B' - c;
				cnt = 1;
			}
		}
		else cnt++;
	}
	if(cnt) ans++;
	
	cout << ans;
	
	return 0;
}