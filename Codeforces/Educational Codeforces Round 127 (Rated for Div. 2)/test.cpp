#include <bits/stdc++.h>

using namespace std;

int main()
{
	string s;
	hash<string> str_hash;
	
	cin >> s;
	cout << s << ": " << str_hash(s) << '\n';
	
	s = to_string(str_hash(s));
	cout << s << ": " << str_hash(s) << '\n';
	
	return 0;
}
