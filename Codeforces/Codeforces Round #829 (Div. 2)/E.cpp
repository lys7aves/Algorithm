#include <iostream>

#define MAX 998244353
#define MAXN 200000

using namespace std;

int a[MAXN+10];

long long power(long long x, long long y)
{
    long long ret;

    if(y == 0) return 1;

    ret = power(x, y/2);
    ret = (ret*ret) % MAX;
    if(y%2 == 1) ret = (ret * x) % MAX;

    return ret;
}

int main()
{
    long long t, n, cnt0, wrong, nC2, ans, i;

    cin >> t;
    while(t--){
        cin >> n;

        cnt0 = 0;
        for(i=0; i<n; i++){
            cin >> a[i];
            cnt0 += 1-a[i];
        }

        wrong = 0;
        for(i=0; i<cnt0; i++) wrong += a[i];

        nC2 = (n*(n-1)/2) % MAX;

        ans = 0;
        for(i=wrong; i>0; i--){
            // ans += nC2 / (i^2)
            ans += (nC2 * power((i*i)%MAX, MAX-2)) % MAX;
            ans %= MAX;
        }

        cout << ans << '\n';
    }

    return 0;
}