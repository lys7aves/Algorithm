#include <iostream>
#include <queue>

using namespace std;

int arr[210][210], pat[5][5], dp[210][210][2][40];
queue<int> que;

int main()
{
    int n, m, k, i, j, x, y, z, w, v, mini;

    cin >> n >> m >> k;
    for(i=0; i<n; i++){
        for(j=0; j<m; j++){
            cin >> arr[i][j];
        }
    }
    for(i=0; i<5; i++){
        for(j=0; j<5; j++){
            cin >> pat[i][j];
        }
    }

    que.push(0);
    que.push(0);
    que.push(0);
    que.push(0);
    que.push(1);

    while(!que.empty()){
        x = que.front(); que.pop();
        y = que.front(); que.pop();
        z = que.front(); que.pop();
        w = que.front(); que.pop();
        v = que.front(); que.pop();

        if(x < 0 || x >=n || y < 0 || y >=m) continue;
        if(w > k) continue;

        if(arr[x][y] == 1) continue;
        if(arr[x][y] == 2) z = 1;

        if(dp[x][y][z][w]) continue;
        dp[x][y][z][w] = v;

        que.push(x-1); que.push(y); que.push(z); que.push(w); que.push(v+1);
        que.push(x+1); que.push(y); que.push(z); que.push(w); que.push(v+1);
        que.push(x); que.push(y-1); que.push(z); que.push(w); que.push(v+1);
        que.push(x); que.push(y+1); que.push(z); que.push(w); que.push(v+1);

        for(i=0; i<5; i++){
            for(j=0; j<5; j++){
                if(pat[i][j] == 0) continue;
                que.push(x+i-2); que.push(y+j-2); que.push(z); que.push(w+1); que.push(v+1);
            }
        }
    }

    mini = n*m*3;
    for(i=0; i<=k; i++){
        if(dp[n-1][m-1][1][i] == 0) continue;
        mini = min(mini, dp[n-1][m-1][1][i]);
    }
    if(mini == n*m*3) cout << -1;
    else cout << mini-1;

    return 0;
}