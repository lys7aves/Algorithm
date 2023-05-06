#include <iostream>

using namespace std;

int chk[100010];

int main()
{
	int n, k, i, cnt=0, num=1, x;
	
	cin >> n >> k;
	for(i=0; i<n; i++){
		cin >> x;
		
		if(chk[x] != num) cnt++;
		chk[x] = num;
		
		if(cnt % k == 0) num++;
	}
	
	cout << num;
	
	return 0;
}