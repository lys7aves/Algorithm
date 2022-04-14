#include <iostream>

using namespace std;

int main()
{
	int n, i, j;
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n;
	for(i=0; i<n; i++){
		for(j=i; j<n-1; j++) cout << ' ';
		for(j=0; j<=i; j++) cout << '*';
		cout << '\n';
	}
	
	return 0;
}
