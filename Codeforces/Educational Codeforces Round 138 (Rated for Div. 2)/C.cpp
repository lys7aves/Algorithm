#include <iostream>
#include <algorithm>

using namespace std;

int a[110];

int main()
{
    int t, n, i, k, ai, bi;

    cin >> t;
    while(t--){
        cin >> n;
        for(i=1; i<=n; i++) cin >> a[i];

        sort(a+1, a+n+1);

        for(k=1; k<=n; k++){
            ai = n;
            bi = 1;
            for(i=1; i<=k; i++){
                while(a[ai] > k-i+1) ai--;
                if(ai < bi) break;
                ai--;
                bi++;
            }

            if(i <= k) break;
        }

        cout << k-1 << '\n';
    }
    return 0;
}