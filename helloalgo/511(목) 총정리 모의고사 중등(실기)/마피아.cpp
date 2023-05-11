#include<iostream>
#include<algorithm>
using namespace std;
int n;
int to[500001];
int ind[500001];
bool vis[500001];
int ans;
void check(int here,bool isMafia) {
    if (vis[here])return;
    vis[here]=true;
    if (isMafia)ans++;
    ind[to[here]]--;
    if (ind[to[here]]==0||isMafia) {
        check(to[here],!isMafia);
    }
}
int main() {
    cin >> n;
    for(int i=1;i<=n;i++) {
        cin >> to[i];
        ind[to[i]]++;
    }
    for(int i=1;i<=n;i++) {
        if (ind[i]==0)check(i,true);
    }
    for(int i=1;i<=n;i++) {//all cycle
        if (!vis[i])check(i,false);
    }
    cout << ans;
}