#include <iostream>
#include <vector>
#include <queue>

#define MAXN 100000

using namespace std;

int b[MAXN+10];
vector<int> edge[MAXN+10];
queue<int> que;

int main()
{
    int t, n, k, i, v, u;

    cin >> t;
    while(t--){
        cin >> n;

        k = 0;
        for(i=0; i<=n+1; i++) edge[i].clear();

        for(i=1; i<=n; i++){
            cin >> b[i];
            if(b[i] > i) k = max(k, i);
            edge[b[i]].push_back(i);
        }

        cout << k << '\n';

        que.push(0);
        que.push(n+1);
        while(!que.empty()){
            v = que.front(); que.pop();

            if(v != 0 && v!= n+1) cout << v << ' ';
            for(i=0; i<edge[v].size(); i++){
                u = edge[v][i];
                if(edge[u].size() == 0) cout << u << ' ';
                else que.push(u);
            }
        }
        cout << '\n';
    }
    return 0;
}