#include <iostream>

using namespace std;

int main()
{
    int x, n, a, b, sum=0;

    cin >> x;
    cin >> n;
    while(n--){
        cin >> a >> b;
        sum += a*b;
    }

    if(x == sum) cout << "Yes";
    else cout << "No";

    return 0;
}