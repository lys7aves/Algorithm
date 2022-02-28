#include <iostream>
#include <string>

using namespace std;

bool chk['Z'];

int main()
{
	int t;
	string str;
	bool ans;
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> t;
	while(t--){
		cin >> str;
		
		ans = true;
		chk['R'] = chk['G'] = chk['B'] = false;
		for(int i=0; i<6; i++){
			if(str[i] >= 'a'){
				chk[str[i]-'a'+'A'] = true;
			}
			else{
				ans &= chk[str[i]];
			}
		}
		
		if(ans) cout << "YES\n";
		else cout << "NO\n";
	}
	
	
	return 0;
}
