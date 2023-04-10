#include <iostream>
#include <string>

using namespace std;

int main()
{
    int t, n, i, min_idx;
    string str;

    cin >> t;
    while(t--){
        cin >> n;
        cin >> str;

        min_idx = 0;
        for(i=1; i<n; i++){
            if(str[i] <= str[min_idx]) min_idx = i;
        }

        cout << str[min_idx];
        for(i=0; i<n; i++){
            if(i == min_idx) continue;
            cout << str[i];
        }
        cout << '\n';
    }

    return 0;
}