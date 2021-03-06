#include <bits/stdc++.h>

using namespace std;

long long pow(int a, int b, int c)
{
	if(b == 0) return 1;
	
	long long tmp = pow(a, b/2, c);
	
	if(b%2 == 1) return (((tmp*tmp) % c) * a) % c;
	else return (tmp*tmp) % c;
}

int main()
{
    int a, b, c;

    cin >> a >> b >> c;

    cout << pow(a, b, c);

    return 0;
}
