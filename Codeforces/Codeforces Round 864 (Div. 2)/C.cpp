#include <iostream>

using namespace std;

int main()
{
    int t, n, m, d1, d2, d3, r, c;

    cin >> t;
    while(t--){
        cin >> n >> m;

        r = c = -1;

        cout << "? 1 1\n";
        cout.flush();
        cin >> d1;

        cout << "? " << n << ' ' << m << '\n';
        cout.flush();
        cin >> d2;

        if(d1 + d2 == n-1) r = d1+1;
        if(d1 + d2 == m-1) c = d1+1;

        if(r == -1 && c == -1){
            if(d1+1 <= n && m-d2 >= 1){
                cout << "? " << d1+1 << ' ' << m-d2 << '\n';
                cout.flush();
                cin >> d3;

                if(d3 == 0){
                    r = d1+1;
                    c = m-d2;
                }
                else{
                    r = n-d2;
                    c = d1+1;
                }
            }
            else{
                r = n-d2;
                c = d1+1;
            }
        }
        if(r == -1){
            r = min(d1+1, n);
            cout << "? " << r << ' ' << c << '\n';
            cout.flush();
            cin >> d3;

            r -= d3;
        }
        if(c == -1){
            c = min(d1+1, m);
            cout << "? " << r << ' ' << c << '\n';
            cout.flush();
            cin >> d3;

            c -= d3;
        }

        cout << "! " << r << ' ' << c << '\n';
        cout.flush();
    }
    return 0;
}