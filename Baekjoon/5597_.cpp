#include <iostream>

using namespace std;

bool chk[100];

int main()
{
    int i, x;

    for(i=0; i<28; i++){
        cin >> x;
        chk[x] = true;
    }

    for(i=1; i<=30; i++){
        if(chk[i]) continue;
        cout << i << '\n';
    }

    return 0;
}