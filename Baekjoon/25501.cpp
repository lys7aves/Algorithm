#include <iostream>
#include <string.h>

using namespace std;

int cnt;
char str[1010];

int recursion(const char *s, int l, int r){
    cnt++;
    if(l >= r) return 1;
    else if(s[l] != s[r]) return 0;
    else return recursion(s, l+1, r-1);
}

int isPalindrome(const char *s){
    return recursion(s, 0, strlen(s)-1);
}
int main()
{
    int t;
    
    cin >> t;
    while(t--){
        cin >> str;

        cnt = 0;
        cout << isPalindrome(str) << ' ' << cnt << '\n';
    }

    return 0;
}