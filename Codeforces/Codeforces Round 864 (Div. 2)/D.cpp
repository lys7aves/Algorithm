#include <iostream>
#include <vector>
#include <set>

#define pii pair<long long, long long>

#define MAXN 100010

using namespace std;

long long a[MAXN], sum[MAXN], sz[MAXN], f[MAXN];
vector<int> edge[MAXN];
set<pii> son[MAXN];

void dfs(int v, int p)
{
    int i, u;

    sum[v] = a[v];
    sz[v] = 1;
    f[v] = p;

    for(i=0; i<edge[v].size(); i++){
        u = edge[v][i];
        if(u == p) continue;
        dfs(u, v);

        sum[v] += sum[u];
        sz[v] += sz[u];
        son[v].insert({-sz[u],u});
    }
}
int main()
{
    int n, m, i, u, v, x, z, y, p;

    cin >> n >> m;
    for(i=1; i<=n; i++) cin >> a[i];
    for(i=0; i<n-1; i++){
        cin >> u >> v;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }

    dfs(1, 0);

    while(m--){
        cin >> z >> x;
        if(z == 1){
            cout << sum[x] << '\n';
        }
        else{
            if(son[x].size() == 0) continue;
            auto it = son[x].begin();
            y = (*it).second;
            p = f[x];

            auto fit = son[p].find({-sz[x],x});
            son[p].erase(fit);
            
            sum[x] -= sum[y];
            sz[x] -= sz[y];
            f[x] = y;
            son[x].erase(it);

            sum[y] += sum[x];
            sz[y] += sz[x];
            f[y] = p;
            son[y].insert({-sz[x],x});

            son[p].insert({-sz[y],y});
        }
    }

    return 0;
}