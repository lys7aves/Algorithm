#include <bits/stdc++.h>

#define MAXN 100000

using namespace std;

int main()
{
    int T, n, k;

    cin >> T;
    while(T--){
        cin >> n >> k;
        
        if(k%2 == 0){
            char arr[MAXN];
            for(int i=0; i<n; i++) cin >> arr[i];

            sort(arr, arr+n);
            for(int i=0; i<n; i++) cout << arr[i];
            cout << '\n';
        }
        else{
            char arr[2][MAXN];
            for(int i=0; i<n; i++) cin >> arr[i%2][i/2];

            sort(arr[0], arr[0]+(n+1)/2);
            sort(arr[1], arr[1]+n/2);

            for(int i=0; i<n; i++) cout << arr[i%2][i/2];
            cout << '\n';
        }
    }
    return 0;
}