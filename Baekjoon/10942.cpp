#include <iostream>

#define MAXN 2010

using namespace std;

int arr[MAXN];
bool dp[MAXN][MAXN], chk[MAXN][MAXN];

bool palindrome(int s, int e)
{
    if(e < s) return true;

    if(chk[s][e]) return dp[s][e];
    chk[s][e] = true;

    return dp[s][e] = (arr[s] == arr[e]) & palindrome(s+1, e-1);
}

int main()
{
    int n, m, i, s, e;

    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    for(i=0; i<n; i++) cin >> arr[i];

    for(s=0; s<n; s++){
        for(e=s; e<n; e++){
            palindrome(s, e);
        }
    }

    cin >> m;
    while(m--){
        cin >> s >> e;

        cout << dp[s-1][e-1] << '\n';
    }

    return 0;
}