#include <iostream>
#include <string>

using namespace std;

int main()
{
    int t, n, i, cnt;
    string s;

    cin >> t;
    while(t--){
        cin >> n;
        cin >> s;

        cnt = 0;
        for(i=1; i<n; i++) cnt += s[i] != s[i-1];

        if(s[0] == '0') cnt = max(0, cnt-1);

        cout << cnt << '\n';
    }
    return 0;
}