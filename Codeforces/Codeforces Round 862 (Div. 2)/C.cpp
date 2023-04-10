#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;

long long k[100010];

int main()
{
    int t, n, m, i, idx;
    long long a, b, c;

    cin >> t;
    while(t--){
        cin >> n >> m;
        for(i=0; i<n; i++) cin >> k[i];
        sort(k, k+n);

        while(m--){
            cin >> a >> b >> c;

            if(c <= 0) cout << "NO\n";
            else{
                idx = upper_bound(k, k+n, b-2*sqrt(a*c)) - k;
                if(idx < n && (b-k[idx])*(b-k[idx]) - 4*a*c < 0) cout << "YES\n" << k[idx] << '\n';
                else cout << "NO\n";
            }
        }

        cout << '\n';
    }
    return 0;
}