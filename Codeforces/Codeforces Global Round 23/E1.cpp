#include <iostream>
#include <vector>

using namespace std;

vector<int> s[20];
bool ans[20], is_true[20];

bool question(int k)
{
    cout << "? ";
    cout << s[k].size() << ' ';
    for(int i=0; i<s[k].size(); i++) cout << s[k][i] << ' ';
    cout << '\n';
    cout.flush();

    string str;
    cin >> str;

    if(str == "YES") return true;
    else return false;
}

int main()
{
    int n, m=0;
    int k, i, ans1, ans2, stnd;
    bool before;

    cin >> n;
    for(i=0; (1<<i)<=n; i++);
    m = i;

    for(k=0; k<m; k++){
        for(i=1; i<=n; i++){
            if(i & (1<<k)) s[k].push_back(i);
        }
    }
    
    for(i=0; i<m; i++){
        ans1 = question(i);
        ans2 = question(i);

        ans[i] = ans1;
        is_true[i] = ans1 == ans2;

        if(ans1 != ans2){
            break;
        }
    }

    stnd = i;
    before = ans2;

    for(i=stnd+1; i<m; i++){
        ans1 = question(i);
        ans2 = question(i);

        if(ans1 == ans2){
            ans[i] = ans1;
            is_true[i] = true;
            before = question(stnd);
        }
        else{
            ans[i] = ans1 ^ (ans[stnd] == before);
            is_true[i] = false;
        }
    }

    int answer1=0, answer2=0;
    for(i=0; i<m; i++){
        if(is_true[i]){
            answer1 += ans[i] * (1<<i);
            answer2 += ans[i] * (1<<i);
        }
        else{
            answer1 += ans[i] * (1<<i);
            answer2 += (1-ans[i]) * (1<<i);
        }
    }

    string str;
    cout << "! " << answer1 << '\n';
    cout.flush();
    cin >> str;
    if(str == ":("){
        cout << "! " << answer2 << '\n';
        cout.flush();
        cin >> str;
    }

    return 0;
}