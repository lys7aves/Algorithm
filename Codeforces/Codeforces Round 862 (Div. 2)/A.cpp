#include <iostream>

using namespace std;

int main()
{
    int t, n, i, a, sum;

    cin >> t;
    while(t--){
        cin >> n;

        sum = 0;
        for(i=0; i<n; i++){
            cin >> a;
            sum ^= a;
        }

        if(n%2 == 0) cout << (sum == 0 ? 0 : -1) << '\n';
        else cout << sum << '\n';
    }
    return 0;
}