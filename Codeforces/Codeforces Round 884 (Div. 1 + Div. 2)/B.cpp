#include <bits/stdc++.h>

using namespace std;

int main()
{
    int T, i, n;

    cin >> T;
    while(T--){
        cin >> n;

        if(n == 1) cout << "1\n";
        else if(n == 2) cout << "1 2\n";
        else{
            cout << "2 ";
            for(i=4; i<=n/2+2; i++) cout << i << ' ';
            cout << "1 ";
            for(; i<=n; i++) cout << i << ' ';
            cout << "3\n";
        }
    }
    return 0;
}