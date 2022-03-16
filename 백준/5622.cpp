#include <iostream>
#include <string>

using namespace std;

int t['Z'+1];

int main()
{
	string str;
	int ans=0, i;
	
	for(i=0; i<18; i++){
		t['A'+i] = i/3 + 3;
	}
	t['S'] = 8;
	t['T'] = t['U'] = t['V'] = 9;
	t['W'] = t['X'] = t['Y'] = t['Z'] = 10;
	
	cin >> str;
	for(i=0; i<str.size(); i++){
		ans += t[str[i]];
	}
	
	cout << ans;
	
	return 0;
}
