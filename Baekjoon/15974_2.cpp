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

int dp[MAXN+10][MAXN+10][2];
// dp[i][0] : i-th vertex is a convex vertex
// dp[i][1] : i-th vertex is a concave vertex
int pre[MAXN+10][MAXN+10][2];

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
        dp[i][0][0] = 1;

        for(j=1; j<i; j++){
            if(is_same_gradient(i, j)) break;

            for(k=0; k<j; k++){
                if(is_convex(k, j, i)){
                    if(dp[j][k][0]+1 > dp[i][j][1]){
                        dp[i][j][1] = dp[j][k][0]+1;
                        pre[i][j][1] = k;
                    }
                }
                if(is_concave(k, j, i)){
                    if(dp[j][k][1]+1 > dp[i][j][0]){
                        dp[i][j][0] = dp[j][k][1]+1;
                        pre[i][j][0] = k;
                    }
                }
            }
        }
    }

    i = j = k = 0;
    for(int ii=0; ii<n; ii++){
        for(int jj=0; jj<ii; jj++){
            if(dp[ii][jj][0] > dp[i][j][0]){
                i = ii;
                j = jj;
            }
        }
    }

    if(j == 0){
        cout << 0;
    }
    else{
        cout << dp[i][j][0] + 1 << '\n';
        cout << point[0].x << ' ' << point[0].y << '\n';
        while(i){
            cout << point[i].x << ' ' << point[i].y << '\n';

            int tmp = pre[i][j][k];
            i = j;
            j = tmp;
            k = 1-k;
        }
    }

    return 0;
}   