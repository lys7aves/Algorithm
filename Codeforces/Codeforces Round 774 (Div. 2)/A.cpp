#include <iostream>

using namespace std;

int main()
{
	int t;
	long long n, s;
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> t;
	while(t--){
		cin >> n >> s;
		cout << s/(n*n) << '\n';
	}
	
	return 0;
}
