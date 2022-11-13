#include <iostream>

using namespace std;

long long K[110], D[110], A[110];

int main()
{
    int n, m, i, k, d, a;
    long long award, sum;

    cin >> n;
    while(n--){
        cin >> m;
        for(i=0; i<m; i++){
            cin >> K[i] >> D[i] >> A[i];
        }
        cin >> k >> d >> a;

        sum = 0;
        for(i=0; i<m; i++){
            award = K[i]*k - D[i]*d + A[i]*a;
            if(award > 0) sum += award;
        }

        cout << sum << '\n';
    }
    return 0;
}