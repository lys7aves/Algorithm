#include <iostream>

using namespace std;

bool check_corner(int x, int y, int n, int m)
{
    if(x == 1 && y == 1) return true;
    if(x == 1 && y == m) return true;
    if(x == n && y == 1) return true;
    if(x == n && y == m) return true;
    return false;
}

bool check_edge(int x, int y, int n, int m)
{
    if(x == 1 || x == n || y == 1 || y == m) return true;
    return false;
}

int main()
{
    int t, n, m, x1, y1, x2, y2;

    cin >> t;
    while(t--){
        cin >> n >> m;
        cin >> x1 >> y1 >> x2 >> y2;

        if(check_corner(x1, y1, n, m) || check_corner(x2, y2, n, m)) cout << 2 << '\n';
        else if(check_edge(x1, y1, n, m) || check_edge(x2, y2, n, m)) cout << 3 << '\n';
        else cout << 4 << '\n';
    }
    return 0;
}