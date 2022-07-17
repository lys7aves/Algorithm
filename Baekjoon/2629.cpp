#include <iostream>

#define MAXN 40
#define ZERO 40500

using namespace std;

bool dp[MAXN][ZERO*2];

int main()
{
    int n, i, j, x, q;

    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;

    dp[0][ZERO] = true;
    for(i=0; i<n; i++){
        cin >> x;
        for(j=0; j<ZERO*2; j++){
            if(dp[i][j]){
                dp[i+1][j-x] = true;
                dp[i+1][j+x] = true;
                dp[i+1][j] = true;
            }
        }
    }

    cin >> q;
    while(q--){
        cin >> x;

        cout << (dp[n][x+ZERO] ? 'Y' : 'N') << ' ';
    }

    return 0;
}