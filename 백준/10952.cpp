#include <iostream>

using namespace std;

int main()
{
	int a, b;
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	while(1){
		cin >> a >> b;
		
		if(a == 0 && b == 0) break;
		
		cout << a+b << '\n';
	}
	
	return 0;
}
