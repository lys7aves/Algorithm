#include <iostream>
#include <algorithm>

using namespace std;

int arr[10];

int main()
{
    int i, sum=0;

    for(i=0; i<5; i++){
        cin >> arr[i];
        sum += arr[i];
    }

    sort(arr, arr+5);

    cout << sum/5 << '\n' << arr[2];

    return 0;
}