#include <iostream>
#include <cstdio>

using namespace std;

int arr[1010];

int main()
{
    int C, n, i, cnt;
    double avg;

    cin >> C;
    while(C--){
        cin >> n;
        avg = cnt = 0;
        for(i=0; i<n; i++){
            cin >> arr[i];
            avg += arr[i];
        }
        avg /= n;
        for(i=0; i<n; i++){
            if(arr[i] > avg) cnt++;
        }

        printf("%.3lf%%\n", 100.0*cnt/n);
    }
    return 0;
}