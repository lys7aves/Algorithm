#include <iostream>

#define MAXN 200000

using namespace std;

int p[MAXN+10], h[MAXN+10];

int main()
{
    int t, n, k, i, l, m, r, cnt;

    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> t;
    while(t--){
        cin >> n >> k;
        for(i=2; i<=n; i++) cin >> p[i];

        l = 1;
        r = n;
        while(l < r){
            m = (l+r) / 2;

            for(i=1; i<=n; i++) h[i] = 0;
            cnt = 0;
            for(i=n; i>=2; i--){
                if(h[i] == m-1 && p[i] != 1) cnt++;
                else h[p[i]] = max(h[p[i]], h[i]+1);
            }

            if(cnt <= k) r = m;
            else l = m+1;
        }

        cout << l << '\n';
    }

    return 0;
}