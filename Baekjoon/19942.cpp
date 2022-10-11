#include <iostream>

using namespace std;

int n, mini=500*15+1;
int mx[4], x[500][5], sum[5];
bool chk[500], ans[500];

void dfs(int p)
{
    if(p == n){
        int i, j;

        for(i=0; i<5; i++) sum[i] = 0;
        for(i=0; i<n; i++){
            for(j=0; j<5; j++){
                sum[j] += x[i][j] * chk[i];
            }
        }

        for(i=0; i<4; i++) if(sum[i] < mx[i]) break;

        if(i<4) return;

        if(sum[4] < mini){
            mini = sum[4];
            for(i=0; i<n; i++) ans[i] = chk[i];
        }
        else if(sum[4] == mini){
            for(i=0; i<n; i++) if(ans[i] != chk[i]) break;
            for(; i<n; i++) if(chk[i]) break;

            if(i == n){
                for(i=0; i<n; i++) ans[i] = chk[i];
            }
        }

        return;
    }

    chk[p] = true;
    dfs(p+1);
    chk[p] = false;
    dfs(p+1);
}

int main()
{
    int i, j;

    cin >> n;
    for(i=0; i<4; i++) cin >> mx[i];
    for(i=0; i<n; i++){
        for(j=0; j<5; j++) cin >> x[i][j];
    }

    dfs(0);

    if(mini == 500*15+1){
        cout << -1;
    }
    else{
        cout << mini << '\n';
        for(i=0; i<n; i++) if(ans[i]) cout << i+1 << ' ';
    }

    return 0;
}