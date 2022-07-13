#include <iostream>
#include <queue>

using namespace std;

priority_queue<int> small, big;

int main()
{
    int n, x;

    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    while(n--){
        cin >> x;

        if(small.empty()) small.push(x);
        else{
            if(x <= small.top()) small.push(x);
            else big.push(-x);
        }

        if(small.size() > big.size()+1){
            big.push(-small.top());
            small.pop();
        }
        if(small.size() < big.size()){
            small.push(-big.top());
            big.pop();
        }

        cout << small.top() << '\n';
    }

    return 0;
}