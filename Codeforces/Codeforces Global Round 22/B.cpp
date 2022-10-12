#include <iostream>

using namespace std;

int s[100000];

int main()
{
    int t, n, k, i;
    bool flag;

    cin >> t;
    while(t--){
        cin >> n >> k;
        for(i=0; i<k; i++) cin >> s[i];

        flag = true;

        if((s[1]-s[0])*(long long)(n-k+1) < s[0]) flag = false;
        for(i=2; i<k; i++){
            if(s[i]-s[i-1] < s[i-1]-s[i-2]) flag = false;
        }

        cout << ((flag | k == 1) ? "Yes\n" : "No\n");
    }
    return 0;
}