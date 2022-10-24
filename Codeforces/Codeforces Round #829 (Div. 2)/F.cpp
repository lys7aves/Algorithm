#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

#define pii pair<int, int>
#define pi3 pair<long long, pii>

#define fir first
#define sec second.first
#define thi second.second

#define MAXN 300000
#define MAX 9000000000000000000

using namespace std;

int n, m;
long long p, q;
string beach[MAXN+10];
vector<long long> dp[MAXN+10];
vector<bool> visit[MAXN+10];
priority_queue<pi3> pq;

void check(int x, int y, long long z, bool f)
{
    if(x < 0 || x >=n || y < 0 || y >= m) return;
    if(beach[x][y] == '.' || beach[x][y] == '#') return;

    if(beach[x][y] == 'U'){
        if(!f) z += q;
        else z += p;
        pq.push({z,{x+1,y}});
    }
    if(beach[x][y] == 'D'){
        if(!f) z += q;
        else z += p;
        pq.push({z,{x-1,y}});
    }
    if(beach[x][y] == 'L'){
        if(!f) z += p;
        else z += q;
        pq.push({z,{x,y+1}});
    }
    if(beach[x][y] == 'R'){
        if(!f) z += p;
        else z += q;
        pq.push({z,{x,y-1}});
    }
}

int main()
{
    int i, j, x, y;
    long long z, ans;

    cin >> n >> m;
    cin >> p >> q;
    for(i=0; i<n; i++){
        cin >> beach[i];
        dp[i].resize(m,0);
        visit[i].resize(m,0);
        for(j=0; j<m; j++){
            if(beach[i][j] == '.'){
                pq.push({0,{i,j}});
            }
        }
    }

    while(!pq.empty()){
        z = pq.top().fir;
        x = pq.top().sec;
        y = pq.top().thi;
        pq.pop();

        if(x < 0 || x >=n || y < 0 || y >= m) continue;

        if(visit[x][y]) continue;
        visit[x][y] = true;
        dp[x][y] = z;

        check(x-1, y, z, 0);
        check(x+1, y, z, 0);
        check(x, y-1, z, 1);
        check(x, y+1, z, 1);
    }

    ans = MAX;
    for(i=0; i<n; i++){
        for(j=0; j<m; j++){
            if(i+1 < n && visit[i][j] & visit[i+1][j]){
                ans = min(ans, dp[i][j]+dp[i+1][j]);
            }
            if(j+1 < m && visit[i][j] & visit[i][j+1]){
                ans = min(ans, dp[i][j]+dp[i][j+1]);
            }
        }
    }

    if(ans == MAX) cout << -1;
    else cout << ans;
    
    return 0;
}