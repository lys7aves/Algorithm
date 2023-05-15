#include <bits/stdc++.h>

#define pii pair<long long, long long>
#define MAXN 300000

using namespace std;

pii a[MAXN+10];
set<pii> s;

int main()
{
    long long T, n, i;
    long long ans, sum_l, x, ll, lr, l, r;

    cin >> T;
    while(T--){
        cin >> n;
        for(i=1; i<=n; i++){
            cin >> a[i].first;
            a[i].second = i;
        }

        sort(a+1, a+n+1);

        s.clear();
        s.insert({0,0});
        s.insert({n+1,n+1});
        ans = 0;
        for(i=1; i<=n; i++){
            x = a[i].second;
            auto it = s.lower_bound({x,0});
            it--;
            lr = it->second;
            ll = it->first;

            ans += (x-lr) * (x-lr-1) / 2;
            if(ll){
                ans += (x-lr-1) * (lr-ll+1);
                ans += (x-ll+1 + x-1) * (ll-1) / 2;
            }
            else ans += (x-lr-1) * lr;

            cout << a[i].first << ' ' << x << ' ' << ll << ' ' << lr << ' ' << ans << '\n';

            //cout << l << ' ' << x << ' ' << r << ' ' << a[i].first << ' ' << sum_l << ' ' << ans << '\n';

            l = r = x;

            auto r_it = s.lower_bound({x, 0});
            auto l_it = r_it;
            l_it--;

            if(r_it->first == x+1){
                r = r_it->second;
                s.erase(r_it);
            }
            if(l_it->second == x-1){
                l = l_it->first;
                s.erase(l_it);
            }
            s.insert({l, r});
        }

        cout << ans << '\n';
    }
    return 0;
}