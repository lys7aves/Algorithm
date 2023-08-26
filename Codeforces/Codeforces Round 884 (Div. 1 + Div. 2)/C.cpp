#include <bits/stdc++.h>

#define MAXN 200000
#define MAX 200000000000000

using namespace std;

long long c[MAXN+10], dp[MAXN+10], maxi[2];

int main()
{
    int T, n, i;
    long long ans;

    cin >> T;
    while(T--){
        cin >> n;

        ans = -MAX;
        maxi[0] = maxi[1] = 0;
        for(i=1; i<=n; i++){
            cin >> c[i];
            dp[i] = maxi[i%2] + c[i];
            maxi[i%2] = max(maxi[i%2], dp[i]);

            ans = max(ans, dp[i]);
        }

        cout << ans << '\n';
    }
    return 0;
}