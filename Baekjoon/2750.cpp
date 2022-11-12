#include <iostream>
#include <algorithm>

using namespace std;

int arr[1010];

int main()
{
    int n, i;

    cin >> n;
    for(i=0; i<n; i++) cin >> arr[i];

    sort(arr, arr+n);

    for(i=0; i<n; i++) cout << arr[i] << '\n';

    return 0;
}