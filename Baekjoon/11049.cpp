#include <iostream>

using namespace std;

int arr[510], dp[510][510];

void dfs(int l, int r)
{
    int m, res;

    if(r == m+1) return;
    if(dp[l][r]) return;

    for(m=l+1; m<r; m++){
        dfs(l, m);
        dfs(m, r);

        res = dp[l][m] + dp[m][r] + arr[l]*arr[m]*arr[r];

        if(dp[l][r] == 0) dp[l][r] = res;
        dp[l][r] = min(dp[l][r], res);
    }
}

int main()
{
    int n, i, r, c;

    cin >> n;
    for(i=0; i<n; i++){
        cin >> r >> c;
        arr[i] = r;
        arr[i+1] = c;
    }
    
    dfs(0, n);

    cout << dp[0][n];

    return 0;
}