#include <iostream>
#include <algorithm>

using namespace std;

int cnt[500010];

int main()
{
    int n, x, i, a;
    bool flag;

    cin >> n >> x;
    for(i=0; i<n; i++){
        cin >> a;
        cnt[a]++;
    }

    for(i=1; i<x; i++){
        if(cnt[i] == 0) continue;

        if(cnt[i] % (i+1)) break;
        cnt[i+1] += cnt[i]/(i+1);
    }

    if(i < x) cout << "NO";
    else cout << "YES";

    return 0;
}