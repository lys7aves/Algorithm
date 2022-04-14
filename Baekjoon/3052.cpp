#include <iostream>

using namespace std;

bool chk[42];

int main()
{
	int i, x, cnt=0;
	
	for(i=0; i<10; i++){
		cin >> x;
		
		cnt += !chk[x%42];
		chk[x%42] = true;
	}
	
	cout << cnt;
	
	return 0;
}
