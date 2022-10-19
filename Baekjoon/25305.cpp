#include <iostream>
#include <functional>
#include <algorithm>

using namespace std;

int arr[1010];

int main()
{
    int n, k, i;

    cin >> n >> k;
    for(i=0; i<n; i++) cin >> arr[i];

    sort(arr, arr+n, greater<int>());

    cout << arr[k-1];

    return 0;
}