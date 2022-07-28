#include <iostream>
#include <vector>

#define MAXV 20010

using namespace std;

bool flag;
int group[MAXV];
vector<int> edge[MAXV];

void dfs(int v, int g)
{
    if(group[v]){
        flag &= (group[v] == g);
        return;
    }
    group[v] = g;

    for(int i=0; i<edge[v].size(); i++){
        dfs(edge[v][i], 3-g);
    }
}

int main()
{
    int T, v, e, i, u;

    cin >> T;
    while(T--){
        cin >> v >> e;

        for(i=1; i<=v; i++){
            edge[i].clear();
            group[i] = 0;
        }

        while(e--){
            cin >> u >> v;
            edge[u].push_back(v);
            edge[v].push_back(u);
        }

        flag = true;
        for(i=1; i<=v; i++){
            if(!group[i]) dfs(i, 1);
        }

        if(flag) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}