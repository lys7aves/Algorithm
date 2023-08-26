#include <bits/stdc++.h>

using namespace std;

int main()
{
    int T, n, i, t, j;

    cin >> T;
    while(T--){
        cin >> n;
        for(t=2; t<=n; t++){
            if(n%t != 0) break;
        }

        for(i=0; i<n; i++){
            cout << char('a' + (i%t));
        }
        cout << '\n';
    }
    return 0;
}