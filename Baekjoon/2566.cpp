#include <iostream>

using namespace std;

int arr[10][10];

int main()
{
    int i, j, x=0, y=0;

    for(i=0; i<9; i++){
        for(j=0; j<9; j++){
            cin >> arr[i][j];
            if(arr[i][j] > arr[x][y]){
                x = i;
                y = j;
            }
        }
    }

    cout << arr[x][y] << '\n';
    cout << x+1 << ' ' << y+1;

    return 0;
}