#include <iostream>

using namespace std;

int arr[5000];

int main()
{
    int n, i, ans=0;

    cin >> n;
    for(i=0; i<n; i++){
        cin >> arr[i];
    }

    for(i=0; i<n; i++){
        if(arr[i] == 0) continue;
        ans++;
        arr[i+1] = max(0, arr[i+1]-arr[i]);
    }

    cout << ans;
    
    return 0;
}