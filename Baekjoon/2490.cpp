#include <iostream>

using namespace std;

int main()
{
    int i, j, x, sum;

    for(i=0; i<3; i++){
        sum = 0;
        for(j=0; j<4; j++){
            cin >> x;
            sum += 1-x;
        }
        if(sum == 0) cout << "E\n";
        else cout << (char)('A' + sum - 1) << '\n';
    }
    return 0;
}