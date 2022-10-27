#include <iostream>

using namespace std;

int arr[110];

int main()
{
    int n, i, v, cnt=0;

    cin >> n;
    for(i=0; i<n; i++) cin >> arr[i];
    cin >> v;

    for(i=0; i<n; i++) if(arr[i] == v) cnt++;

    cout << cnt;

    return 0;
}