#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

unordered_map<long long, int> decide[51];
long long X[51];

int main()
{
    int b, n, i, j, cnt;
    long long x;
    string str;

    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> b;
    for(i=0; i<b; i++){
        cin >> str;
        x = 0;
        for(j=0; j<str.size(); j++) x = (x << 1) | (str[j]-'0');

        decide[str.size()][x] = 1;
    }
    for(i=0; i<b; i++){
        cin >> str;
        x = 0;
        for(j=0; j<str.size(); j++) x = (x << 1) | (str[j]-'0');

        if(decide[str.size()].find(x) == decide[str.size()].end()) decide[str.size()][x] = -1;
        else decide[str.size()].erase(x);
    }

    cin >> n;
    while(n--){
        cin >> str;

        cnt = 0;
        for(i=1; i<=50; i++) X[i] = 0;
        for(i=0; i<str.size(); i++){
            for(j=1; j<=50; j++){
                X[j] = (X[j] << 1) | (str[i]-'0');
                X[j] &= (1L<<j) - 1;
                if(i < j-1) continue;
                if(decide[j].find(X[j]) != decide[j].end()){
                    cnt += decide[j][X[j]];
                }
            }
        }

        if(cnt == 0) cout << "GOOD\n";
        else if(cnt > 0) cout << "HIGH " << cnt << '\n';
        else cout << "LOW " << -cnt << '\n';
    }
    return 0;
}