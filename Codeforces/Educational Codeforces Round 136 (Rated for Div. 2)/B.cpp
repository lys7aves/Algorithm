#include <iostream>

using namespace std;

int d[110];

int main()
{
    int t, n, i, a;
    bool flag;

    cin >> t;
    while(t--){
        cin >> n;

        cin >> d[0];

        flag = true;
        for(i=1; i<n; i++){
            cin >> a;
            d[i] = d[i-1] + a;
            if(d[i-1] - a >= 0) flag = false;
        }

        if(flag){
            for(i=0; i<n; i++) cout << d[i] << ' ';
            cout << '\n';
        }
        else cout << "-1\n";
    }
    
    return 0;
}