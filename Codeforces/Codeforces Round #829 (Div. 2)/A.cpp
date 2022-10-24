#include <iostream>
#include <string>

using namespace std;

int main()
{
    int t, n, i, q;
    string str;

    cin >> t;
    while(t--){
        cin >> n;
        cin >> str;

        q = 0;
        for(i=0; i<str.size(); i++){
            if(str[i] == 'Q') q++;
            if(str[i] == 'A') q--;
            if(q < 0) q = 0;
        }
        
        if(q == 0) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}