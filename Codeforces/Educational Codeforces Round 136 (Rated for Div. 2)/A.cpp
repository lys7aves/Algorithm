#include <iostream>

using namespace std;

int main()
{
	int t, n, m;

    cin >> t;
    while(t--){
        cin >> n >> m;

        if(n == 1 || m == 1) cout << "1 1\n";
        else cout << "2 2\n";
    }
    
	return 0;
}