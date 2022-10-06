#include <iostream>
#include <vector>

#define MAXN 300000

using namespace std;

int n, m;
long long ans;
bool one_cycle=false;
int level[MAXN+10];
int cycle_end[MAXN+10], cycle_start[MAXN+10];
vector<int> edge[MAXN+10];

int dfs(int v, int p)
{
    int i, u, cycle=0, cycle_=0;
    bool child_flag=true;

    for(i=0; i<edge[v].size(); i++){
        u = edge[v][i];

        if(u == p) continue;
        if(level[u] == 0){
            level[u] = level[v]+1;
            int ret = dfs(u, v);

            ret -= cycle_start[v];
            cycle_end[v] += cycle_start[v];
            cycle_start[v] = 0;

            if(ret > 1) child_flag = false;
            cycle += ret;
        }
        if(level[u] < level[v]){
            cycle_end[v]++;
            cycle_start[u]++;
            cycle_++;
        }
        else if(level[u] > level[v]) continue;
    }

    if(one_cycle){
        if(cycle + cycle_end[v]) ans += v;
    }
    else{
        if(cycle + cycle_end[v] == m-n+1 && child_flag) ans += v;
    }

    return cycle + cycle_;
}

int main()
{
    int i, u, v;

    cin >> n >> m;
    for(i=0; i<m; i++){
        cin >> u >> v;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }

    if(n == m) one_cycle = true;

    level[1] = 1;
    dfs(1, 0);

    cout << ans;

    return 0;
}