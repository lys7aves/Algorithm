#include <iostream>
#include <vector>
#include <algorithm>

#define MAXN 100010

using namespace std;

int cnt;
bool visited[MAXN];
int number[MAXN];
vector<int> edge[MAXN];

void dfs(int r)
{
    visited[r] = true;
    number[r] = ++cnt;

    for(int i=0; i<edge[r].size(); i++){
        if(!visited[edge[r][i]]) dfs(edge[r][i]);
    }
}

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
        sort(edge[i].begin(), edge[i].end());
    }

    dfs(r);

    for(i=1; i<=n; i++){
        cout << number[i] << '\n';
    }

    return 0;
}