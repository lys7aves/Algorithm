#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <queue>

#define MAXN 100010

using namespace std;

int cnt;
bool visited[MAXN];
int number[MAXN];
vector<int> edge[MAXN];
queue<int> que;

int main()
{
    int n, m, r, i, u,  v;

    cin >> n >> m >> r;
    while(m--){
        cin >> u >> v;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }

    for(i=1; i<=n; i++){
        sort(edge[i].begin(), edge[i].end(), greater<int>());
    }

    visited[r] = true;
    que.push(r);
    while(!que.empty()){
        u = que.front();
        que.pop();

        number[u] = ++cnt;

        for(auto v: edge[u]){
            if(!visited[v]){
                visited[v] = true;
                que.push(v);
            }
        }
    }

    for(i=1; i<=n; i++){
        cout << number[i] << '\n';
    }

    return 0;
}