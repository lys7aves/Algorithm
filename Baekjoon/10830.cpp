#include <iostream>

using namespace std;

int n;
int A[10][10], res[10][10], tmp[10][10];

void matrix_product(int x[10][10], int y[10][10])
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
            res[i][j] = tmp[i][j] % 1000;
        }
    }
}

void power(long long x)
{
    int i, j;

    if(x == 1){
        for(i=0; i<n; i++){
            for(j=0; j<n; j++){
                res[i][j] = A[i][j] % 1000;
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

    cin >> n >> b;
    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            cin >> A[i][j];
        }
    }

    power(b);

    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            cout << res[i][j] % 1000 << ' ';
        }
        cout << '\n';
    }

    return 0;
}