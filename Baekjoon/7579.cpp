#include <iostream>
#include <algorithm>

#define MAXN 110
#define MAXC 100

using namespace std;

int dp[MAXN][MAXN*MAXC];
int m[MAXN], c[MAXN];

int main()
{
    int n, M, i, j;

    cin >> n >> M;
    for(i=1; i<=n; i++) cin >> m[i];
    for(i=1; i<=n; i++) cin >> c[i];

    for(i=1; i<=n; i++){
        for(j=0; j<MAXN*MAXC; j++){
            dp[i][j] = dp[i-1][j];
            if(j-c[i] >= 0) dp[i][j] = max(dp[i][j], dp[i-1][j-c[i]] + m[i]);
        }
    }

    for(i=0; i<MAXN*MAXC; i++){
        if(dp[n][i] >= M){
            cout << i;
            break;
        }
    }

    return 0;
}