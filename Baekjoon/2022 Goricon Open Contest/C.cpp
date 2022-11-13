#include <iostream>
#include <algorithm>

using namespace std;

pair<int,int> domino[500010];

int main()
{
    int n, i, cnt, x;

    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    for(i=0; i<n; i++){
        cin >> domino[i].first >> domino[i].second;
    }

    sort(domino, domino+n);

    cnt = x = 0;
    for(i=0; i<n; i++){
        if(domino[i].first > x) cnt++;
        x = domino[i].first + domino[i].second;
    }

    cout << cnt;

    return 0;
}