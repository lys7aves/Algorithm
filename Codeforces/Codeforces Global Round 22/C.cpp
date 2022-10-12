#include <iostream>

using namespace std;

bool dp[110][110][2];

int main()
{
    int t, n, i, j, k, cnt, a;

    dp[0][0][0] = true;
    dp[0][0][1] = false;

    for(i=1; i<=100; i++){
        dp[i][0][0] = true;
        dp[i][0][1] = false;

        for(j=1; j<i; j++){
            for(k=0; k<2; k++){
                dp[i][j][k] = !dp[i-1][j-1][(j%2)^k^1];
                if(i!=j) dp[i][j][k] |= !dp[i-1][j][(j%2)^k^1];
            }
        }
    }

    for(i=0; i<=10; i++){
        for(j=0; j<=10; j++){
            cout << dp[i][j][0] << ',' << dp[i][j][1] << ' ';
        }
        cout << '\n';
    }

    cin >> t;
    while(t--){
        cin >> n;
        cnt = 0;
        for(i=0; i<n; i++){
            cin >> a;
            cnt += a%2;
        }

        cout << (dp[n][cnt] ? "Alice" : "Bob") << '\n';
    }
    return 0;
}