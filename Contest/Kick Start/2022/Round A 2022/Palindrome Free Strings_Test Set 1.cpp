#include <bits/stdc++.h>

#define POSSIBLE "POSSIBLE\n"
#define IMPOSSIBLE "IMPOSSIBLE\n"

using namespace std;

int N;
string S;
bool ans;

bool check_sub_palindrome(int l, int r)
{
	for(int i=0; i<r-l; i++){
		if(S[l+i] != S[r-i-1]) return false;
	}
	
	return true;
}

void dfs(int p)
{
	if(ans) return;
	
	if(p == N){
		int i, j;
		
		for(i=0; i<N; i++){
			for(j=i+5; j<=N; j++){
				if(check_sub_palindrome(i, j)) return;
			}
		}
		
		ans = true;
		
		return;
	}
	
	if(S[p] == '?'){
		S[p] = '0';
		dfs(p+1);
		S[p] = '1';
		dfs(p+1);
		S[p] = '?';
	}
	else{
		dfs(p+1);
	}
}

int main()
{
	int T, C;
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> T;
	for(C=1; C<=T; C++){
		cout << "Case #" << C << ": ";
		
		cin >> N;
		cin >> S;
		
		ans = false;
		dfs(0);
		
		if(ans) cout << POSSIBLE;
		else cout << IMPOSSIBLE;
	}
	
	return 0;
}
