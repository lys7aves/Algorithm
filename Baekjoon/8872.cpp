#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

#define pii pair<int,int>

#define MAXN 100000

using namespace std;

vector<pii> edge[MAXN+10];
vector<int> radius;
bool chk[MAXN+10];

pii find_farthest_vertex(int v)
{
    int u, t, i;
    pii ret={v, 0};

    if(chk[v]) return {v, -1};
    chk[v] = true;

    for(i=0; i<edge[v].size(); i++){
        u = edge[v][i].first;
        t = edge[v][i].second;

        pii res = find_farthest_vertex(u);
        if(res.second == -1) continue;

        if(ret.second < res.second + t){
            ret.first = res.first;
            ret.second = res.second + t;
        }
    }

    return ret;
}

void clear_check(int v)
{
    int i;

    if(!chk[v]) return;
    chk[v] = false;

    for(i=0; i<edge[v].size(); i++){
        clear_check(edge[v][i].first);
    }
}

int get_radius(int v, int u, int d)
{
    static bool flag=false;
    int r=-1, i;

    if(chk[v]) return -1;
    chk[v] = true;

    if(v == u){
        if(d) flag = true;
        return 0;
    }

    for(i=0; i<edge[v].size(); i++){
        int ret = get_radius(edge[v][i].first, u, d);
        if(ret == -1) continue;

        if(!flag) r = ret;
        else if(ret+edge[v][i].second >= d/2.0){
            flag = false;
            r = min(ret + edge[v][i].second, d - ret);
        }
        else r = ret + edge[v][i].second;
    }

    return r;
}

int main()
{
    int n, m, l, i, a, b, t, ans=0;
    pii ret1, ret2;

    cin >> n >> m >> l;
    for(i=0; i<m; i++){
        cin >> a >> b >> t;
        edge[a].push_back({b, t});
        edge[b].push_back({a, t});
    }

    for(i=0; i<n; i++){
        if(chk[i]) continue;

        ret1 = find_farthest_vertex(i);

        clear_check(i);
        ret2 = find_farthest_vertex(ret1.first);

        // if all the islands are already connected, the answer is the diameter of the tree.
        ans = max(ans, ret2.second);

        clear_check(i);
        int r = get_radius(ret1.first, ret2.first, ret2.second);
        radius.push_back(r);
    }

    sort(radius.begin(), radius.end(), greater<int>());

    if(radius.size() > 1) ans = max(ans, radius[0] + l + radius[1]);
    if(radius.size() > 2) ans = max(ans, radius[1] + 2*l + radius[2]);

    cout << ans;
    
    return 0;
}