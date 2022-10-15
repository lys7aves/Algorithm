#include <iostream>
#include <set>

using namespace std;

set<int> s;
int arr[100010], ans[100010];

int main()
{
    int t, n, i, x;

    cin >> t;
    while(t--){
        cin >> n;
        for(i=1; i<=n; i++){
            cin >> arr[i];
            s.insert(i);
        }

        for(i=1; i<=n; i++){
            x = arr[i-1] - arr[i] + 1;

            auto it = s.lower_bound(x);
            ans[*it] = i;
            s.erase(it);
        }

        for(i=1; i<=n; i++) cout << ans[i] << ' ';
        cout << '\n';
    }
    return 0;
}