#include <bits/stdc++.h>

using namespace std;

int gcd(int x, int y){ return y==0 ? x : gcd(y, x%y); }

int main()
{
    int T, n, i, x, ans;

    cin >> T;
    while(T--){
        cin >> n;
        
        ans = -1;
        for(i=1; i<=n; i++){
            cin >> x;
            if(x == i) continue;
            if(ans == -1) ans = abs(x-i);
            ans = gcd(ans, abs(x-i));
        }

        cout << ans << '\n';
    }
    return 0;
}