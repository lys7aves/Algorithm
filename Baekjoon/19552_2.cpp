#include <iostream>

#define pii pair<int,int>
#define MAXN 3000
#define MAXM 9000

using namespace std;

int n, m, k, v=3, e=3, f=1;
pii points[MAXN+10], edges[MAXM+10];

int gcd(int x, int y){ return y == 0 ? x : gcd(y, x%y); }

void limit(int a, int b, int x, int *l, int *u)
{
    int ax, ay, bx, by, y, z;

    ax = points[a].first;
    ay = points[a].second;
    bx = points[b].first;
    by = points[b].second;

    y = (bx-ax)*ay + (x-ax)*(by-ay);

    if(bx-ax == 0) return;
    z = (bx-ax)/abs(bx-ax);
    if(z > 0){
        y = (y-1)/(bx-ax) + 1; // 올림
        *l = max(*l, y);
    }
    else{
        y = y/(bx-ax); // 내림
        *u = min(*u, y);
    }
}

bool check(int a, int x, int y)
{
    int p, q;

    p = abs(x - points[a].first);
    q = abs(y - points[a].second);

    if(gcd(p, q) == 1) return true;
    else return false;
}

pii find_vertex(int a, int b, int c)
{
    int i, j, li=2, ui=78, x=0, y=0;

    if(points[a].first == points[b].first){
        if(points[a].second < points[b].second) ui = points[a].first-1;
        else li = points[a].first+1;
    }
    if(points[b].first == points[c].first){
        if(points[b].second < points[c].second) ui = points[b].first-1;
        else li = points[b].first+1;
    }
    if(points[c].first == points[a].first){
        if(points[c].second < points[a].second) ui = points[c].first-1;
        else li = points[c].first+1;
    }

    for(i=li; i<=ui; i++){
        int l=2, u=78;

        limit(a, b, i, &l, &u);
        limit(b, c, i, &l, &u);
        limit(c, a, i, &l, &u);

        for(j=l; j<=u; j++){
            if(points[a].first == i && points[a].second == j) continue;
            if(points[b].first == i && points[b].second == j) continue;
            if(points[c].first == i && points[c].second == j) continue;

            x = i;
            y = j;
            if(!check(a, i, j)) continue;
            if(!check(b, i, j)) continue;
            if(!check(c, i, j)) continue;

            return {i, j};
        }
    }

    return {x, y};
}

void dfs(int a, int b, int c)
{
    if(f >= k) return;

    pii p = find_vertex(a, b, c);
    if(p.first == 0) return;

    points[++v] = p;
    edges[++e] = {a, v};
    edges[++e] = {b, v};
    if(++f >= k) return;

    edges[++e] = {c, v};
    f++;

    int _v = v;
    dfs(a, b, _v);
    dfs(b, c, _v);
    dfs(c, a, _v);
}

int main()
{
    freopen("output.txt","w",stdout);
    
    int i, j, num;

    cin >> n >> m >> k;

    if(k == 0){
        num = 0;
        for(i=1; i<=79; i++){
            for(j=1; j<=79; j++){
                if(++num <= n) cout << i << ' ' << j << '\n';
            }
        }
        for(i=1; i<=m; i++) cout << i << ' ' << i+1 << '\n';

        return 0;
    }

    points[1] = {1,1};
    points[2] = {79,1};
    points[3] = {2,79};
    edges[1] = {1, 2};
    edges[2] = {2, 3};
    edges[3] = {3, 1};

    dfs(1, 2, 3);

    points[++v] = {3, 79};
    edges[++e] = {3, v};
    for(i=4; i<=79; i++){
        for(j=79; j>=79-i+3; j--){
            if(v < n) points[++v] = {i, j};
            if(e < m) edges[++e] = {v, v-1};
        }
    }

    for(i=1; i<=n; i++) cout << points[i].first << ' ' << points[i].second << '\n';
    for(i=1; i<=m; i++) cout << edges[i].first << ' ' << edges[i].second << '\n';

    cout << v << ' ' << e << ' ' << f << '\n';

    return 0;
}