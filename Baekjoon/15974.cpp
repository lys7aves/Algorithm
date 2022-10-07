#include <iostream>
#include <algorithm>

#define pii pair<int,int>

#define MAXN 3000
#define MAX_COR 100000000

using namespace std;

struct cor{
    long long x, y;
};

cor heel={MAX_COR,MAX_COR};
cor point[MAXN+10];

pii dp[MAXN+10][2];
// dp[i][0] : i-th vertex is a convex vertex
// dp[i][1] : i-th vertex is a concave vertex   
// first : number of contained vertex
// second : previous vertex number

bool cmp_gradient(const cor a, const cor b)
{
    // 뒷꿈치 좌표 맨 앞으로 보내기
    if(a.y == heel.y) return true;
    if(b.y == heel.y) return false;

    cor da, db;
    da = {a.x - heel.x, a.y - heel.y};
    db = {b.x - heel.x, b.y - heel.y};

    return da.x * db.y - db.x * da.y < 0;
}

bool is_convex(int a, int b, int c)
{
    cor p, q;
    p = {point[b].x - point[a].x, point[b].y - point[a].y};
    q = {point[c].x - point[a].x, point[c].y - point[a].y};

    return p.x*q.y - q.x*p.y < 0;
}

bool is_concave(int a, int b, int c)
{
    cor p, q;
    p = {point[b].x - point[a].x, point[b].y - point[a].y};
    q = {point[c].x - point[a].x, point[c].y - point[a].y};

    return p.x*q.y - q.x*p.y > 0;
}

bool is_lower_gradient(int i, int j1, int j2)
{
    cor ij1, ij2;

    ij1 = {point[j1].x - point[i].x, point[j1].y - point[i].y};
    ij2 = {point[j2].x - point[i].x, point[j2].y - point[i].y};
    
    return ij1.x * ij2.y - ij2.x * ij1.y > 0;
}

bool is_higher_gradient(int i, int j1, int j2)
{
    cor ij1, ij2;

    ij1 = {point[j1].x - point[i].x, point[j1].y - point[i].y};
    ij2 = {point[j2].x - point[i].x, point[j2].y - point[i].y};
    
    return ij1.x * ij2.y - ij2.x * ij1.y < 0;
}

bool is_same_gradient(int i, int j)
{
    cor hi, hj;

    hi = {point[i].x - heel.x, point[i].y - heel.y};
    hj = {point[j].x - heel.x, point[j].y - heel.y};

    return hi.x * hj.y - hj.x * hi.y == 0;
}

int main()
{
    int n, i, j, k;

    cin >> n;
    for(i=0; i<n; i++){
        cin >> point[i].x >> point[i].y;
        if(point[i].y < heel.y) heel = point[i];
    }

    sort(point, point+n, cmp_gradient);

    for(i=1; i<n; i++){
        // all vertex can be first convex vertex.
        dp[i][0] = {1, 0};

        for(j=1; j<i; j++){
            if(is_same_gradient(i, j)) break;

            if(is_convex(dp[j][0].second, j, i)){
                if(dp[i][1].first < dp[j][0].first+1){
                    dp[i][1].first = dp[j][0].first+1;
                    dp[i][1].second = j;
                }
                else if(dp[i][1].first == dp[j][0].first+1){
                    if(is_lower_gradient(i, j, dp[i][1].second)){
                        dp[i][1].second = j;
                    }
                }
            }
            if(dp[j][1].first > 0 && is_concave(dp[j][1].second, j, i)){
                if(dp[i][0].first < dp[j][1].first+1){
                    dp[i][0].first = dp[j][1].first+1;
                    dp[i][0].second = j;
                }
                else if(dp[i][0].first == dp[j][1].first+1){
                    if(is_higher_gradient(i, j, dp[i][0].second)){
                        dp[i][0].second = j;
                    }
                }
            }
        }
    }

    j = k = 0;
    for(i=0; i<n; i++){
        if(dp[i][0].first > dp[j][0].first) j = i;
    }

    if(dp[j][0].first == 1){
        cout << 0;
    }
    else{
        cout << dp[j][0].first + 1 << '\n';
        cout << point[0].x << ' ' << point[0].y << '\n';
        while(j){
            cout << point[j].x << ' ' << point[j].y << '\n';
            j = dp[j][k].second;
            k = 1-k;
        }
    }

    return 0;
}   