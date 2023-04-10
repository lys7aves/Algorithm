#include <iostream>

using namespace std;

int arr[1010][1010];

int main()
{
    int t, n, k, i, j, cnt;

    cin >> t;
    while(t--){
        cin >> n >> k;
        for(i=0; i<n; i++){
            for(j=0; j<n; j++){
                cin >> arr[i][j];
            }
        }

        cnt = 0;
        for(i=0; i<n; i++){
            for(j=0; j<n; j++){
                cnt += arr[i][j] ^ arr[n-i-1][n-j-1];
            }
        }
        cnt /= 2;

        if(k < cnt) cout << "NO\n";
        else if(n%2 == 1 || (k-cnt)%2 == 0) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}