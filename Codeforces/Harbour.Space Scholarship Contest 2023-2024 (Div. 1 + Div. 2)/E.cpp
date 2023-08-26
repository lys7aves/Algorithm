#include <bits/stdc++.h>

#define MAX 998244353

using namespace std;

int s[200010];

long long gcd(long long x, long long y){ return y == 0LL ? x : gcd(y, x%y); }

long long power(long long x, int y)
{
    if(y == 0) return 1LL;

    long long res = power(x, y/2);
    res = (res * res) % MAX;
    if(y%2 == 1) res = (res * x) % MAX;

    return res;
}

void print_answer(long long p, long long q)
{
    long long g = gcd(p, q);

    p /= g;
    q /= g;

    //cout << p << ' ' << q << '\n';

    long long q_ = power(q, MAX-2);

    cout << ((p % MAX) * q_) % MAX  << '\n';
}

int main()
{
    int T, i, j, base;
    int *sp, *ep, *np;
    long long n, sum, cnt;

    cin >> T;
    while(T--){
        cin >> n;
        for(i=0; i<n; i++) cin >> s[i];

        sort(s, s+n);

        sum = 0;
        for(i=0; i<n; i++){
            vector<int> ones;
            for(j=30; j>=0; j--){
                if(s[i] & (1<<j)) ones.push_back(j);
            }

            cnt = 0;
            sp = s;
            ep = s+n;
            base = 0;
            for(j=0; j<ones.size(); j++){
                if(j%2 == 0){
                    np = lower_bound(sp, ep, base + (1<<(ones[j]+1)));
                    cnt += (int)(ep - np) * (j+1);
                    ep = np;
                }
                else{
                    np = lower_bound(sp, ep, base + (1<<(ones[j])));
                    cnt += (int)(np - sp) * (j+1);
                    sp = np;
                }

                base |= 1<<ones[j];
            }
            if(j%2 == 0) cnt += (ep - sp) * (j+1);
            else{
                np = upper_bound(sp, ep, s[i]);
                cnt += (np - sp) * (j+1);
                cnt += (ep - np) * (j+2);
            }

            //cout << i << " : " << cnt << '\n';

            sum += cnt;
        }

        print_answer(sum, n*n);
    }
    return 0;
}