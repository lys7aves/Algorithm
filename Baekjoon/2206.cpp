#include <cstdio>
#include <queue>
#include <algorithm>

using namespace std;

int maze[1010][1010], visited[1010][1010][2];
queue<int> que;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int main()
{
    int n, m, i, j, x, y, z, num, ans=-1;

    scanf("%d %d", &n, &m);
    for(i=1; i<=n; i++){
        for(j=1; j<=m; j++){
            scanf("%1d", &maze[i][j]);
        }
    }

    que.push(1);
    que.push(1);
    que.push(0);
    que.push(1);
    while(!que.empty()){
        x = que.front(); que.pop();
        y = que.front(); que.pop();
        z = que.front(); que.pop();
        num = que.front(); que.pop();

        if(x < 1 || x > n) continue;
        if(y < 1 || y > m) continue;

        if(maze[x][y]) z++;
        if(z == 2) continue;

        if(visited[x][y][z]) continue;
        visited[x][y][z] = num;

        for(i=0; i<4; i++){
            que.push(x+dx[i]);
            que.push(y+dy[i]);
            que.push(z);
            que.push(num+1);
        }
    }

    if(visited[n][m][0]) ans = visited[n][m][0];
    if(visited[n][m][1]){
        if(ans == -1) ans = visited[n][m][1];
        else ans = min(ans, visited[n][m][1]);
    }

    printf("%d", ans);

    return 0;
}