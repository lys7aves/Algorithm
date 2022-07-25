#include <iostream>
#include <queue>

#define MAXL 300

using namespace std;

int visited[MAXL+10][MAXL+10];
queue<int> que;

int dx[8]={-2, -2, -1, -1, 1, 1, 2, 2};
int dy[8]={-1, 1, -2, 2, -2, 2, -1, 1};

int main()
{
    int T, l, xs, ys, xe, ye, x, y, z, i, j;

    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> T;
    while(T--){
        cin >> l;
        cin >> xs >> ys;
        cin >> xe >> ye;

        for(i=0; i<l; i++) for(j=0; j<l; j++) visited[i][j] = 0;
        while(!que.empty()) que.pop();
        
        que.push(xs);
        que.push(ys);
        que.push(1);
        while(!que.empty()){
            x = que.front(); que.pop();
            y = que.front(); que.pop();
            z = que.front(); que.pop();

            if(x < 0 || x >= MAXL || y < 0 || y >= MAXL) continue;
            if(x == xe && y == ye) break;

            if(visited[x][y]) continue;
            visited[x][y] = z;

            for(i=0; i<8; i++){
                que.push(x+dx[i]);
                que.push(y+dy[i]);
                que.push(z+1);
            }
        }

        cout << z-1 << '\n';
    }
    return 0;
}