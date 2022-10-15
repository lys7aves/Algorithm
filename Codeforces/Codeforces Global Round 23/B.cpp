#include <iostream>

using namespace std;

int arr[100010];

int main()
{
    int t, n, i, l, r, cnt;

    cin >> t;
    while(t--){
        cin >> n;
        for(i=1; i<=n; i++) cin >> arr[i];

        l = 1;
        r = n;
        cnt = 0;
        while(true){
            while(l <= n && arr[l] == 0) l++;
            while(r >= 1 && arr[r] == 1) r--;

            if(l > r) break;

            cnt++;
            l++;
            r--;
        }

        cout << cnt << '\n';
    }
    return 0;
}