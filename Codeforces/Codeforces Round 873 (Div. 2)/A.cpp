#include<bits/stdc++.h>

using namespace std;

int main()
{
    int T, n, i;

    cin >> T;
    while(T--){
        cin >> n;
        for(i=1; i<=n; i++) cout << 2*i << ' ';
        cout << '\n';
    }
    return 0;
}