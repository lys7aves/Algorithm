#include <iostream>
#include <algorithm>

using namespace std;

bool flag;
int h[10];
bool chk[10];

void dfs(int p, int cnt)
{
    if(flag) return;
    
    if(p == 9){
        if(cnt != 7) return;

        int i, sum=0;
        for(i=0; i<9; i++){
            sum += h[i] * chk[i];
        }

        if(sum == 100){
            flag = true;

            for(i=0; i<9; i++){
                if(chk[i]) cout << h[i] << '\n';
            }
        }

        return;
    }

    chk[p] = true;
    dfs(p+1, cnt+1);

    chk[p] = false;
    dfs(p+1, cnt);
}

int main()
{
    int i;

    for(i=0; i<9; i++) cin >> h[i];

    sort(h, h+9);

    dfs(0, 0);

    return 0;
}