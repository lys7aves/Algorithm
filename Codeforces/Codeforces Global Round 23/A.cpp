#include <iostream>

using namespace std;

int main()
{
    int t, n, k, i, x, ans;

    cin >> t;
    while(t--){
        cin >> n >> k;

        ans = 0;
        for(i=0; i<n; i++){
            cin >> x;
            ans |= x;
        }

        if(ans) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}