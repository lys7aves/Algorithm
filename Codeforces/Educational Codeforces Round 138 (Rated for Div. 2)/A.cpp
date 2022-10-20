#include <iostream>

using namespace std;

int main()
{
    int t, n, m, i, x, y;

    cin >> t;
    while(t--){
        cin >> n >> m;
        for(i=0; i<m; i++) cin >> x >> y;

        if(n == m) cout << "NO\n";
        else cout << "YES\n";
    }
    return 0;
}