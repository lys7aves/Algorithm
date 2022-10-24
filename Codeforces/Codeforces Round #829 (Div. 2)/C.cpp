#include <iostream>
#include <queue>

using namespace std;

int a[200010];
queue<int> que;

int main()
{
    int t, n, i, sum, s, e, cnt;
    bool flag;

    cin >> t;
    while(t--){
        cin >> n;

        sum = 0;
        for(i=1; i<=n; i++){
            cin >> a[i];
            sum += a[i];
        }

        if(abs(sum)%2 == 1){
            cout << "-1\n";
            continue;
        }

        cnt = 0;
        flag = false;
        for(i=1; i<=n; i++){
            if(!flag){
                if(a[i] == 0){
                    cnt++;
                    que.push(i);
                    que.push(i);
                }
                else{
                    s = i;
                    flag = true;
                }
            }
            else{
                if(a[i] == 0) continue;
                else{
                    e = i;
                    flag = false;

                    if(((e-s)%2 == 1) ^ (a[s] != a[e])){
                        cnt++;
                        que.push(s);
                        que.push(e);
                    }
                    else{
                        cnt+=2;
                        que.push(s);
                        que.push(s);
                        que.push(s+1);
                        que.push(e);
                    }
                }
            }
        }

        cout << cnt << '\n';
        while(!que.empty()){
            cout << que.front() << ' ';
            que.pop();
            cout << que.front() << '\n';
            que.pop();
        }
    }

    return 0;
}