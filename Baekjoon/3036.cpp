#include <iostream>

using namespace std;

void print(int a, int b)
{
	int gcd, i;
	
	for(i=1; i<=a; i++){
		if(a%i == 0 && b%i == 0) gcd = i;
	}
	
	cout << a/gcd << '/' << b/gcd << '\n';
}

int main()
{
	int n, i, a, b;
	
	cin >> n;
	cin >> a;
	
	for(i=1; i<n; i++){
		cin >> b;
		print(a, b);
	}
	
	return 0;
}
