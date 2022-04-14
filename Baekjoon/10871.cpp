#include <iostream>

using namespace std;

int main()
{
	int n, x, a;
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n >> x;
	for(int i=0; i<n; i++){
		cin >> a;
		if(a < x) cout << a << ' ';
	}
	
	return 0;
}
