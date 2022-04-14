#include <iostream>
#include <string>

using namespace std;

int main()
{
	string A, B;
	int a, b, i;
	
	cin >> A >> B;
	
	a = b = 0;
	for(i=2; i>=0; i--){
		a = a*10 + A[i] - '0';
		b = b*10 + B[i] - '0';
	}
	
	cout << max(a, b);
	
	return 0;
}
