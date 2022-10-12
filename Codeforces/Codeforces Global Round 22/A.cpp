#include <iostream>
#include <vector>
#include <algorithm>

#define MAXN 100000

using namespace std;

int a[MAXN+10];
vector<int> b[2];

int main()
{
    int t, n, i, j;
    long long ans;

    cin >> t;
    while(t--){
        ans = 0;
        b[0].clear();
        b[1].clear();

        cin >> n;
        for(i=0; i<n; i++) cin >> a[i];
        for(i=0; i<n; i++){
            int _b;
            cin >> _b;

            b[a[i]].push_back(_b);
            ans += 2*_b;
        }

        sort(b[0].begin(), b[0].end());
        sort(b[1].begin(), b[1].end());

        if(b[0].size() == b[1].size()){
            ans -= min(b[0][0], b[1][0]);
        }
        else{
            for(i=0; i<(int)b[0].size()-(int)b[1].size(); i++) ans -= b[0][i];
            for(i=0; i<(int)b[1].size()-(int)b[0].size(); i++) ans -= b[1][i];
        }

        cout << ans << '\n';
    }
    return 0;
}