#include <iostream>
#include <cstdio>
#include <vector>
#include <set>

#define pii pair<int,int>
#define MAXN 3000
#define MAXM 9000

using namespace std;

int n, m, k, v=3, e=3, f=1;
int plane[100][100];
pii points[MAXN+10];
set<pii> edges;

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
    int i, j, li=2, ui=78;

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

            return {i, j};
        }
    }

    return {0,0};
}

pii edge(int a, int b){
    return {min(a,b), max(a,b)};
}

bool in_line(int a, int b, int c)
{
    int x1, y1, x2, y2;

    x1 = points[b].first - points[a].first;
    y1 = points[b].second - points[a].second;
    x2 = points[c].first - points[a].first;
    y2 = points[c].second - points[a].second;

    if(x1*y2 - x2*y1 == 0) return true;
    else return false;
}

void dfs(int a, int b, int c)
{
    int x, y, num;

    if(f >= k) return;
    if(in_line(a, b, c)) return;

    pii p = find_vertex(a, b, c);
    x = p.first;
    y = p.second;
    points[0] = {x, y};
    if(x == 0) return;

    if(plane[x][y]){
        num = plane[x][y];
    }
    else{
        points[++v] = p;
        plane[p.first][p.second] = v;
        num = v;
    }

    if(in_line(a, b, 0)){
        if(edges.find(edge(a,b)) != edges.end()) edges.erase(edge(a,b));
        f--;
    }
    if(in_line(b, c, 0)){
        if(edges.find(edge(b,c)) != edges.end()) edges.erase(edge(b,c));
        f--;
    }
    if(in_line(c, a, 0)){
        if(edges.find(edge(c,a)) != edges.end()) edges.erase(edge(c,a));
        f--;
    }

    edges.insert(edge(a, num));
    edges.insert(edge(b, num));
    edges.insert(edge(c, num));
    f += 2;

    dfs(a, b, num);
    dfs(b, c, num);
    dfs(c, a, num);
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
    points[3] = {1,79};
    edges.insert(edge(1, 2));
    edges.insert(edge(2, 3));
    edges.insert(edge(3, 1));
    plane[1][1] = 1;
    plane[79][1] = 2;
    plane[1][79] = 3;

    dfs(1, 2, 3);

    cout << v << ' ' << edges.size() << ' ' << f << '\n';
    for(i=1; i<=min(v, n); i++) plane[points[i].first][points[i].second] = i;
    for(i=0; i<=79; i++) printf("%4d ", i);
    printf("\n");
    for(i=1; i<=79; i++){
        printf("%4d ", i);
        for(j=1; j<=79; j++){
            printf("%4d ", plane[i][j]);
        }
        cout << '\n';
    }
    cout.flush();
    int tmp;
    cin >> tmp;

    points[++v] = {2, 79};
    if(edges.size() < m) edges.insert(edge(3, v));
    for(i=3; i<=79; i++){
        for(j=79; j>80-i; j--){
            if(v < n) points[++v] = {i, j};
            if(edges.size() < m) edges.insert(edge(v, v-1));
        }
    }

    for(i=1; i<=n; i++) cout << points[i].first << ' ' << points[i].second << '\n';
//    for(i=1; i<=m; i++) cout << edges[i].first << ' ' << edges[i].second << '\n';

    return 0;
}