#include <iostream>
#include <algorithm>

#define pii pair<int,int>

#define MAXN 3000
#define MAX_COR 100000000

using namespace std;

struct cor{
    long long x, y;
    int num;
};

cor heel={MAX_COR,MAX_COR};
cor point[MAXN+10];

int dp[MAXN+10][MAXN+10][2];
// dp[i][j][0] : j-th vertex is a convex vertex
// dp[i][j][1] : j-th vertex is a concave vertex
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
    int n, i, j, k, max_idx;

    cin >> n;
    for(i=0; i<n; i++){
        cin >> point[i].x >> point[i].y;
        if(point[i].y < heel.y) heel = point[i];
    }

    sort(point, point+n, cmp_gradient);
    for(i=0; i<n; i++) point[i].num = i;

    for(i=1; i<n; i++){
        // all vertex can be first convex vertex.
        dp[0][i][0] = 1;

        heel = point[i];
        sort(point+1, point+i, cmp_gradient);
        sort(point+i+1, point+n, cmp_gradient);

        heel = point[0];

        j = max_idx = 0;
        for(k=i+1; k<n; k++){
            if(is_same_gradient(i, point[k].num)) continue;
            while(j < i && is_convex(j, i, k)){
                if(!is_same_gradient(i, point[j].num) && dp[point[j].num][i][0] > dp[max_idx][i][0]){
                    max_idx = point[j].num;
                }
                j++;
            }
            dp[i][point[k].num][1] = dp[max_idx][i][0] + 1;
            pre[i][point[k].num][1] = max_idx;
        }
        
        j = i-1;
        max_idx = 0;
        for(k=n-1; k>i; k--){
            while(j >= 0 && is_concave(j, i, k)){
                if(dp[point[j].num][i][1] > dp[max_idx][i][1]){
                    max_idx = point[j].num;
                }
                j--;
            }
            dp[i][point[k].num][0] = dp[max_idx][i][1] + 1;
            pre[i][point[k].num][0] = max_idx;
        }
        
        sort(point+1, point+i, cmp_gradient);
        sort(point+i+1, point+n, cmp_gradient);
    }

    i = j = k = 0;
    for(int ii=0; ii<n; ii++){
        for(int jj=ii+1; jj<n; jj++){
            if(dp[ii][jj][0] > dp[i][j][0]){
                i = ii;
                j = jj;
            }
        }
    }

    if(i == 0){
        cout << 0;
    }
    else{
        cout << dp[i][j][0] + 1 << '\n';
        cout << point[0].x << ' ' << point[0].y << '\n';
        while(j){
            cout << point[j].x << ' ' << point[j].y << '\n';

            int tmp = pre[i][j][k];
            j = i;
            i = tmp;
            k = 1-k;
        }
    }

    return 0;
}   