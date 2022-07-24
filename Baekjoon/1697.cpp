#include <iostream>
#include <queue>

#define MAXN 100000

using namespace std;

int visited[MAXN+10];

queue<int> que;

int main()
{
    int n, k, x, y;

    cin >> n >> k;

    que.push(n);
    que.push(1);
    while(!que.empty()){
        x = que.front(); que.pop();
        y = que.front(); que.pop();

        if(x == k) break;
        if(x < 0 || x > MAXN) continue;
        if(visited[x]) continue;
        visited[x] = y;

        que.push(x-1); que.push(y+1);
        que.push(x+1); que.push(y+1);
        que.push(x*2); que.push(y+1);
    }

    cout << y-1;

    return 0;
}