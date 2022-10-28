#include <iostream>

using namespace std;

int a[100][100];

int main()
{
    int n, m, i, j, b;

    cin >> n >> m;
    for(i=0; i<n; i++){
        for(j=0; j<m; j++){
            cin >> a[i][j];
        }
    }
    for(i=0; i<n; i++){
        for(j=0; j<m; j++){
            cin >> b;
            cout << a[i][j] + b << ' ';
        }
        cout << '\n';
    }

    return 0;
}