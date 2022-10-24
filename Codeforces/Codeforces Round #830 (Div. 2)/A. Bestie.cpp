#include <iostream>
#include <algorithm>

#define MAX 400

using namespace std;

int n;

int gcd(int x, int y){ return y == 0 ? x : gcd(y, x%y); }

int dfs(int g, int i)
{
    int ret1, ret2;

    if(g == 1) return 0;

    if(i == 0) return MAX;

    ret1 = dfs(g, i-1);
    ret2 = dfs(gcd(g,i), i-1) + n-i+1;

    return min(ret1, ret2);
}

int main()
{
    int t, i, a, g;

    cin >> t;
    while(t--){
        cin >> n;
        for(i=0; i<n; i++){
            cin >> a;
            if(i == 0) g = a;

            g = gcd(g, a);
        }

        cout << dfs(g, n) << '\n';
    }

    return 0;
}