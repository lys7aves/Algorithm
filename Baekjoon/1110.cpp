#include <iostream>

using namespace std;

int main()
{
    int n, x, a, b, cnt=0;

    cin >> n;

    x = n;
    do{
        a = x/10;
        b = x%10;

        x = b*10 + ((a+b)%10);
        cnt++;
    }while(x != n);

    cout << cnt;
    
    return 0;
}