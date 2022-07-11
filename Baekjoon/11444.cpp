#include <iostream>

#define MAX 1000000007

using namespace std;

int n=2;
long long A[2][2], res[2][2], tmp[2][2];

void matrix_product(long long x[2][2], long long y[2][2])
{
    int i, j, k;

    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            tmp[i][j] = 0;
            for(k=0; k<n; k++){
                tmp[i][j] += x[i][k] * y[k][j];
            }
        }
    }

    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            res[i][j] = tmp[i][j] % MAX;
        }
    }
}

void power(long long x)
{
    int i, j;

    if(x == 1){
        for(i=0; i<n; i++){
            for(j=0; j<n; j++){
                res[i][j] = A[i][j] % MAX;
            }
        }

        return;
    }

    power(x/2);

    matrix_product(res, res);
    if(x%2 == 1) matrix_product(res, A);
}

int main()
{
    int i, j;
    long long b;

    cin >> b;
    A[0][0] = 0;
    A[0][1] = 1;
    A[1][0] = 1;
    A[1][1] = 1;

    power(b);

    cout << res[0][1];

    return 0;
}