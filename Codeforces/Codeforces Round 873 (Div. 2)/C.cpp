#include <bits/stdc++.h>

#define MAXN 200000
#define MAX 1000000007

using namespace std;

int a[MAXN+10], b[MAXN+10];

int main()
{
    int T, n, i, j;
    long long ans;

    cin >> T;
    while(T--){
        cin >> n;
        for(i=0; i<n; i++) cin >> a[i];
        for(i=0; i<n; i++) cin >> b[i];

        sort(a, a+n);
        sort(b, b+n);

        j = 0;
        ans = 1;
        for(i=0; i<n; i++){
            while(j < n && a[i] > b[j]) j++;
            ans = (ans*(j-i))%MAX;
        }

        cout << ans << '\n';
    }
    return 0;
}