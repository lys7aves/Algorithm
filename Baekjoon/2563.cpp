#include <iostream>

using namespace std;

bool arr[110][110];

int main()
{
    int n, i, j, x, y, cnt=0;

    cin >> n;

    while(n--){
        cin >> x >> y;
        for(i=x; i<x+10; i++){
            for(j=y; j<y+10; j++){
                arr[i][j] = true;
            }
        }
    }

    for(i=0; i<=100; i++){
        for(j=0; j<=100; j++){
            cnt += arr[i][j];
        }
    }

    cout << cnt;

    return 0;
}