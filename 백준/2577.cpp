#include <iostream>

using namespace std;

int cnt[10];

int main()
{
	int a, b, c, x;
	
	cin >> a >> b >> c;
	
	x = a*b*c;
	while(x){
		cnt[x%10]++;
		x /= 10;
	}
	
	for(int i=0; i<10; i++){
		cout << cnt[i] << '\n';
	}
	
	return 0;
}
