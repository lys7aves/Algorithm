#include <iostream>
#include <vector>
#include <algorithm>

#define MAXN 200000

using namespace std;

int s[MAXN+10], dp[MAXN+10], diff[MAXN+10];
vector<int> child[MAXN+10];

void dfs(int v, int k)
{
    int i, u, k_;
    vector<long long> diffs;

    dp[v] = k*s[v];
    if(child[v].size() == 0){
        diff[v] = s[v];
        return;
    }
    k_ = k/child[v].size();

    for(i=0; i<child[v].size(); i++){
        u = child[v][i];

        dfs(u, k_);
        dp[v] += dp[u];

        diffs.push_back(diff[u]);
    }

    sort(diffs.begin(), diffs.end(), greater<int>());

    for(i=0; i<k%child[v].size(); i++){
        dp[v] += diffs[i];
    }
    diff[v] = diffs[k%child[v].size()] + s[v];
}

int main()
{
    int t, n, k, i, p;

    cin >> t;
    while(t--){
        cin >> n >> k;

        for(i=1; i<=n; i++) child[i].clear();

        for(i=2; i<=n; i++){
            cin >> p;
            child[p].push_back(i);
        }
        for(i=1; i<=n; i++) cin >> s[i];

        dfs(1, k);

        cout << dp[1] << '\n';
    }
    return 0;
}