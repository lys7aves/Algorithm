#include <iostream>

#define MAXN 200000

using namespace std;

long long a[MAXN+10], b[MAXN+10];

int main()
{
    int t, n, i, j;
    long long ans;

    cin >> t;
    while(t--){
        cin >> n;
        for(i=0; i<n; i++) cin >> a[i];
        for(i=0; i<n; i++) cin >> b[i];

        i = 0;
        j = n-1;
        ans = 0;
        while(i <= j){
            if(b[i] < b[j]){
                ans += a[i];
                a[i+1] += b[i];
                i++;
            }
            else{
                ans += a[j];
                a[j-1] += b[j];
                j--;
            }
        }
        
        cout << ans << '\n';
    }

    return 0;
}