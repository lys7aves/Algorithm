#include <iostream>
#include <queue>
#include <algorithm>

#define MAXN 110

using namespace std;

int box[MAXN][MAXN][MAXN];
queue<int> que;

int dx[6] = {-1, 1, 0, 0, 0, 0};
int dy[6] = {0, 0, -1, 1, 0, 0};
int dz[6] = {0, 0, 0, 0, -1, 1};

int main()
{
    int m, n, h, i, j, k, x, y, z, maxi=0;
    bool flag=false;

    cin >> m >> n >> h;
    for(k=1; k<=h; k++){
        for(i=1; i<=n; i++){
            for(j=1; j<=m; j++){
                cin >> box[i][j][k];

                if(box[i][j][k] == 1){
                    que.push(i);
                    que.push(j);
                    que.push(k);
                }

                if(box[i][j][k] == 0) flag = true;
            }
        }
    }

    if(!flag){
        cout << 0;
        return 0;
    }

    while(!que.empty()){
        x = que.front(); que.pop();
        y = que.front(); que.pop();
        z = que.front(); que.pop();
        maxi = max(maxi, box[x][y][z]);

        for(i=0; i<6; i++){
            if(x+dx[i] <= 0 || x+dx[i] > n) continue;
            if(y+dy[i] <= 0 || y+dy[i] > m) continue;
            if(z+dz[i] <= 0 || z+dz[i] > h) continue;

            if(box[x+dx[i]][y+dy[i]][z+dz[i]] == 0){
                que.push(x+dx[i]);
                que.push(y+dy[i]);
                que.push(z+dz[i]);
                box[x+dx[i]][y+dy[i]][z+dz[i]] = box[x][y][z] + 1;
            }
        }
    }

    flag = false;
    for(k=1; k<=h; k++){
        for(i=1; i<=n; i++){
            for(j=1; j<=m; j++){
                if(box[i][j][k] == 0) flag = true;
            }
        }
    }

    if(flag) cout << -1;
    else cout << maxi-1;

    return 0;
}