#include <iostream>

using namespace std;

int arr[5000], arr_[5000], dp[5000];

int main()
{
    int n, i, j, flag, cnt;

    cin >> n;
    for(i=1; i<=n; i++){
        cin >> arr[i];
    }

    // dp[i] = dp[i-1] + 1
    // 2개씩 묶는걸 성공하면 dp[n] = dp[j] + a

    dp[1] = 1;
    for(i=2; i<=n; i++){
        dp[i] = dp[i-1] + 1;
        for(j=1; j<=n; j++) arr_[j] = arr[j];

        cnt = 0;
        flag = 1;
        for(j=i; j>=1; j--){
            if(arr_[j] == 0) break;

            if(arr_[j-1] < arr_[j]){
                flag = 0;
                break;
            }
            arr_[j-1] -= arr_[j];
            cnt++;
        }

        if(flag == 1) dp[i] = min(dp[i], dp[j-1] + cnt);
    }

    cout << dp[n];
    
    return 0;
}