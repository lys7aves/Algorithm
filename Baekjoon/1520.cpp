#include <iostream>
#include <vector>
#include <algorithm>

#define pii pair<int, int>
#define piii pair<int, pii>

using namespace std;

int arr[510][510], dp[510][510];
vector<piii> order;

int dx[4]={-1, 1, 0, 0};
int dy[4]={0, 0, -1, 1};

int main()
{
    int n, m, i, j, x, y;

    cin >> n >> m;
    for(i=1; i<=n; i++){
        for(j=1; j<=m; j++){
            cin >> arr[i][j];
            order.push_back({-arr[i][j], {i, j}});
        }
    }

    sort(order.begin(), order.end());

    dp[1][1] = 1;
    for(auto it: order){
        x = it.second.first;
        y = it.second.second;

        for(i=0; i<4; i++){
            if(arr[x][y] < arr[x+dx[i]][y+dy[i]]){
                dp[x][y] += dp[x+dx[i]][y+dy[i]];
            }
        }
    }

    cout << dp[n][m];

    return 0;
}