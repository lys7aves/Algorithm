#include <iostream>

#define MAX 998244353

using namespace std;

long long w[100], l[100], C[100][100];

int main()
{
    int t, n, i, j;

    for(i=0; i<=60; i++){
        C[i][0] = 1;
        for(j=1; j<=i; j++){
            C[i][j] = (C[i-1][j-1] + C[i-1][j]) % MAX;
        }
    }

    w[2] = 1;
    for(i=4; i<=60; i+=2){
        w[i] = (C[i-1][i/2] + l[i-2]) % MAX;
        l[i] = (C[i-2][i/2] + w[i-2]) % MAX;
    }

    cin >> t;
    while(t--){
        cin >> n;
        cout << w[n] << ' ' << l[n] << " 1\n";
    }
    
    return 0;
}