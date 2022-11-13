#include <iostream>

using namespace std;

int arr[3010][3010], order[3010];

int main()
{
    int n, m, q, i, j, x, k;

    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m >> q;
    for(i=0; i<n; i++){
        order[i] = i;
        for(j=0; j<m; j++){
            cin >> arr[i][j];
        }
    }

    while(q--){
        cin >> x >> i >> j;
        if(x == 0){
            cin >> k;
            arr[order[i]][j] = k;
        }
        else{
            k = order[i];
            order[i] = order[j];
            order[j] = k;
        }
    }

    for(i=0; i<n; i++){
        for(j=0; j<m; j++){
            cout << arr[order[i]][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}