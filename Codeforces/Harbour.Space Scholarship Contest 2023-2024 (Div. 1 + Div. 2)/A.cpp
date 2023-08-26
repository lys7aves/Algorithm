#include <bits/stdc++.h>

using namespace std;

int main()
{
    int T, x, y, n, b;

    cin >> T;
    while(T--){
        cin >> x >> y >> n;

        stack<int> answer;

        answer.push(y);
        for(int i=1; i<n; i++) answer.push(answer.top()-i);

        if(answer.top() >= x){
            cout << x << ' ';
            answer.pop();
            while(!answer.empty()){
                cout << answer.top() << ' ';
                answer.pop();
            }
            cout << '\n';
        }
        else cout << "-1\n";
    }
    
    return 0;
}