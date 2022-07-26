#include <iostream>
#include <queue>

using namespace std;

int up[110], down[110];
bool visited[110];
queue<int> que;

int main()
{
    int n, m, x, y, i;

    cin >> n >> m;
    while(n--){
        cin >> x >> y;
        up[x] = y;
    }
    while(m--){
        cin >> x >> y;
        down[x] = y;
    }

    que.push(1);
    que.push(0);
    while(!que.empty()){
        x = que.front(); que.pop();
        y = que.front(); que.pop();

        if(x > 100) continue;
        if(visited[x]) continue;
        visited[x] = true;

        if(up[x]) x = up[x];
        if(down[x]) x = down[x];
        visited[x] = true;

        if(x == 100) break;

        for(i=1; i<=6; i++){
            que.push(x+i);
            que.push(y+1);
        }
    }

    cout << y;

    return 0;
}