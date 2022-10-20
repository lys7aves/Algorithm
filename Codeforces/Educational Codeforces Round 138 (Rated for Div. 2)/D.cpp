#include <iostream>

#define MAXN 300000
#define MAX 998244353

using namespace std;

bool p[MAXN+10];

int main()
{
    int n, i, j;
    long long m, all_, unambi, ans=0, ps=1;

    cin >> n >> m;

    for(i=2; i<=n; i++){
        if(p[i]) continue;
        for(j=i+i; j<=n; j+=i) p[j] = true;
    }

    all_ = unambi = m % MAX;
    for(i=2; i<=n; i++){
        all_ = (all_ * (m%MAX)) % MAX;

        if(unambi){
            if(!p[i]) ps *= i;
            unambi = (unambi * ((m/ps)%MAX)) % MAX;
        }

        ans = (ans + all_ - unambi + MAX) % MAX;
    }

    cout << ans;

    return 0;
}