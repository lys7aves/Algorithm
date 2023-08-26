#include <bits/stdc++.h>

using namespace std;

int main()
{
    int T, x, i, k;

    cin >> T;
    while(T--){
        cin >> x;

        k = 0;
        for(i=1; i<=x; i<<=1){
            k++;
            if(x&i) k++;
        }

        cout << k-1 << '\n';
        for(i=1; i<x; i<<=1){
            if(x&i){
                cout << x << ' ';
                x ^= i;
            }
        }
        for(; x; x>>=1) cout << x << ' ';
        cout << '\n';
    }
    return 0;
}