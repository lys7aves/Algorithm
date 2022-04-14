#include <bits/stdc++.h>

using namespace std;

int main()
{
	int a, b, v;
	
	cin >> a >> b >> v;
	
	if(v == a) cout << 1;
	else cout << (v-a-1)/(a-b)+2;
	
	return 0;
}
