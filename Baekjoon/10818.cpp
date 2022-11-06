#include <iostream>
#include <algorithm>

#define MAX 1000000

using namespace std;

int main()
{
    int n, i, x, mini=MAX, maxi=-MAX;

    cin >> n;
    for(i=0; i<n; i++){
        cin >> x;

        mini = min(mini, x);
        maxi = max(maxi, x);
    }

    cout << mini << ' ' << maxi;

    return 0;
}