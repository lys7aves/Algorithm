#include <bits/stdc++.h>

using namespace std;

int main()
{
	int x, i, j;
	
	cin >> x;
	for(i=1; x>i*(i+1)/2; i++);
	
	j = x - (i-1)*i/2;
	
	if(i%2 == 1) cout << i-j+1 << '/' << j;
	else cout << j << '/' << i-j+1;
	
	return 0;
}
