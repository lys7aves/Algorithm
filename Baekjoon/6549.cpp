#include <iostream>
#include <stack>
#include <algorithm>

#define MAXN 100010

using namespace std;

int n;
int h[MAXN], l[MAXN], r[MAXN];
stack<int> s;

void solved()
{
    int i;
    long long ans=0;

    s.push(0);
    for(i=1; i<=n; i++){
        while(h[s.top()] >= h[i]) s.pop();

        l[i] = s.top() + 1;
        s.push(i);
    }
    while(!s.empty()) s.pop();

    s.push(n+1);
    for(i=n; i>=1; i--){
        while(h[s.top()] >= h[i]) s.pop();

        r[i] = s.top() - 1;
        s.push(i);
    }
    while(!s.empty()) s.pop();

    for(i=1; i<=n; i++){
        ans = max(ans, (long long)h[i] * (r[i]-l[i]+1));
    }

    cout << ans << '\n';
}

int main()
{
    int i;

    while(1){
        cin >> n;

        if(n == 0) break;

        for(i=1; i<=n; i++) cin >> h[i];
        h[0] = h[n+1] = -1;

        solved();
    }

    return 0;
}