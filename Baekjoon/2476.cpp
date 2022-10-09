#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n, i, maxi=0, point, a, b, c;

    cin >> n;
    while(n--){
        cin >> a >> b >> c;

        if(a == b && a == c) point = 10000 + a*1000;
        else if(a == b) point = 1000 + a*100;
        else if(b == c) point = 1000 + b*100;
        else if(c == a) point = 1000 + c*100;
        else point = max(a, max(b, c)) * 100;

        maxi = max(maxi, point);
    }

    cout << maxi;

    return 0;
}