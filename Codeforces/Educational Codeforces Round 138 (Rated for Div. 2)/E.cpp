#include <iostream>
#include <string>
#include <queue>

#define MAXN 200000

#define pii pair<int, int>
#define pi4 pair<pii, pii>
#define pi5 pair<int, pi4>
#define fir first
#define sec second.first.first
#define thi second.first.second
#define fou second.second.first
#define fif second.second.second

using namespace std;

int n, m;
vector<int> d[MAXN+10], pre_x[MAXN+10], pre_y[MAXN+10];
string field[MAXN+10];
priority_queue<pi5> pq;


bool check(int x, int y, int z){
    if(x < 0 || x >= n || y < 0 || y >= m) return false;
    if(field[x][y] == '.'){
        if(x-1 >= 0 && field[x-1][y] == '#') return false;
        if(y-1 >= 0 && field[x][y-1] == '#') return false;
        if(y+1 < m && field[x][y+1] == '#') return false;
        if(x+1 < n && field[x+1][y] == '#') return false;
        z++;
    }

    if(d[x][y] && d[x][y] <= z) return false;
    return true;
}

int main()
{
    int t, i, j, x, y, x_, y_, z, ans;

    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> t;
    while(t--){
        cin >> n >> m;
        for(i=0; i<n; i++){
            cin >> field[i];
            d[i].resize(m);
            pre_x[i].resize(m);
            pre_y[i].resize(m);
        }

        for(i=0; i<n; i++){
            pq.push({1, {{i, 0},{-1,-1}}});
        }

        while(!pq.empty()){
            z = pq.top().fir;
            x = pq.top().sec;
            y = pq.top().thi;
            x_ = pq.top().fou;
            y_ = pq.top().fif;
            pq.pop();

            if(x < 0 || x >= n || y < 0 || y >= m) continue;
            if(field[x][y] == '.'){
                if(x-1 >= 0 && field[x-1][y] == '#') continue;
                if(y-1 >= 0 && field[x][y-1] == '#') continue;
                if(y+1 < m && field[x][y+1] == '#') continue;
                if(x+1 < n && field[x+1][y] == '#') continue;
                z++;
            }

            if(d[x][y] && d[x][y] <= z) continue;
            d[x][y] = z;
            pre_x[x][y] = x_;
            pre_y[x][y] = y_;
            if(check(x-1, y-1, z)) pq.push({z, {{x-1, y-1}, {x, y}}});
            if(check(x-1, y+1, z)) pq.push({z, {{x-1, y+1}, {x, y}}});
            if(check(x+1, y-1, z)) pq.push({z, {{x+1, y-1}, {x, y}}});
            if(check(x+1, y+1, z)) pq.push({z, {{x+1, y+1}, {x, y}}});
        }

        ans = n*m;
        for(i=0; i<n; i++){
            if(d[i][m-1]) ans = min(ans, d[i][m-1]);
        }

        for(i=0; i<n; i++){
            if(d[i][m-1] == ans){
                x = i;
                y = m-1;
                while(x >= 0){
                    field[x][y] = '#';
                    x_ = pre_x[x][y];
                    y_ = pre_y[x][y];
                    x = x_;
                    y = y_;
                }
                break;
            }
        }

        if(ans == n*m) cout << "NO\n";
        else{
            cout << "YES\n";
            for(i=0; i<n; i++){
                cout << field[i] << '\n';
            }
        }

/*        for(i=0; i<n; i++){
            for(j=0; j<m; j++){
                cout << d[i][j] << ' ';
            }
            cout << '\n';
        }*/

        // reset
        for(i=0; i<n; i++){
            d[i].clear();
            pre_x[i].clear();
            pre_y[i].clear();
        }
    }
    return 0;
}