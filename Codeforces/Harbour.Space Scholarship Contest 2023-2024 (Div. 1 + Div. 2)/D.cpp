#include <bits/stdc++.h>

using namespace std;

int arr[3010][3010], sum[20010];
int main()
{
    int T, n, i, j, x, y, cnt;
    bool flip;

    scanf("%d", &T);
    while(T--){
        scanf("%d", &n);
        for(i=0; i<n; i++){
            for(j=0; j<n; j++){
                scanf("%1d", &arr[i][j]);
            }
        }
        for(i=0; i<4*n; i++) sum[i] = 0;

        cnt = 0;
        for(i=0; i<2*n; i++){
            flip=0;
            for(j=i; j>=0; j--){
                x = i-j;
                y = j;
                flip ^= sum[x-y+2*n-1];
                flip ^= sum[x-y+2*n];

                if(x < n && y < n && (arr[x][y] ^ flip)){
                    sum[x-y+2*n] ^= 1;
                    flip ^= 1;
                    cnt++;
                }
            }
        }

        cout << cnt << '\n';
    }
    return 0;
}