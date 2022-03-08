#include <iostream>
#include <string>

using namespace std;

int main()
{
	int t, i;
	string str;
	char c;
	bool ans;
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> t;
	while(t--){
		cin >> str;
		cin >> c;
		
		ans = false;
		for(i=0; i<str.size(); i++){
			if(str[i] == c && i%2 == 0) ans = true;
		}
		
		if(ans) cout << "YES\n";
		else cout << "NO\n";
	}
	
	return 0;
}
