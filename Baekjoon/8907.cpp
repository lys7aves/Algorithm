#include <iostream>

using namespace std;

int arr[1010][1010], cnt[2];

int main()
{
    int t, n, i, j, sum;

    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> t;
    while(t--){
        cin >> n;
        for(i=0; i<n; i++){
            for(j=i+1; j<n; j++){
                cin >> arr[i][j];
                arr[j][i] = arr[i][j];
            }
        }

        sum = 0;
        for(i=0; i<n; i++){
            cnt[0] = cnt[1] = 0;
            for(j=0; j<n; j++){
                if(i == j) continue;
                cnt[arr[i][j]]++;
            }

            sum += cnt[0] * cnt[1];
        }

        cout << n*(n-1)*(n-2)/6 - sum/2 << '\n';
    }
    return 0;
}