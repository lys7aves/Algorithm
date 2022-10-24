#include <iostream>

using namespace std;

int ans[1010];

int main()
{
    int t, n, i, j;

    cin >> t;
    while(t--){
        cin >> n;
        
        j = (n+1)/2;
        for(i=0; i<n; i++){
            ans[i] = j;
            if(j <= (n+1)/2) j += n/2;
            else j -= n/2+1;
        }

        for(i=0; i<n; i++) cout << ans[i] << ' ';
        cout << '\n';
    }

    return 0;
}