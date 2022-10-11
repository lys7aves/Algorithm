#include <iostream>

using namespace std;

bool chk[510][510];
int main()
{
    int n, x1, y1, x2, y2, i, j, sum=0;

    cin >> n;
    while(n--){
        cin >> x1 >> y1 >> x2 >> y2;
        for(i=x1; i<x2; i++){
            for(j=y1; j<y2; j++){
                chk[i][j] = true;
            }
        }
    }

    for(i=0; i<500; i++){
        for(j=0; j<500; j++){
            sum += chk[i][j];
        }
    }

    cout << sum;
    
    return 0;
}