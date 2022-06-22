#include <bits/stdc++.h>

#define POSSIBLE "POSSIBLE\n"
#define IMPOSSIBLE "IMPOSSIBLE\n"

using namespace std;

int N;
string substring[2]={"100101", "100110"};
bool chk[2][6];
bool ans;
char S_[50010];

bool check_sub_palindrome(int l, int r)
{
	if(l < 0 || r > N || r-l < 5) return false;
	
	for(int i=0; i<r-l; i++){
		if(S_[l+i] != S_[r-i-1]) return false;
	}
	
	return true;
}

void dfs(int p)
{
	if(ans) return;
	if(p == 2){
		dfs(N-2);
		return;
	}
	if(p == N){
		int i, j;
		for(i=0; i<2; i++){
			for(j=i+5; j<=8; j++){
				if(check_sub_palindrome(i, j)) return;
			}
		}
		for(i=N-9; i<N-7; i++){
			for(j=i+5; j<=N; j++){
				if(check_sub_palindrome(i, j)) return;
			}
		}
		
		ans = true;
		
		return;
	}
	
	if(S_[p] == '?'){
		S_[p] = '0';
		dfs(p+1);
		S_[p] = '1';
		dfs(p+1);
		S_[p] = '?';
	}
	else{
		dfs(p+1);
	}
}

int main()
{
	int T, C, i, j, k;
	string S;
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> T;
	for(C=1; C<=T; C++){
		cin >> N;
		cin >> S;
		
		if(N < 5){
			cout << "Case #" << C << ": ";
			cout << POSSIBLE;
			continue;
		}
		
		for(i=0; i<2; i++) for(j=0; j<6; j++) chk[i][j] = true;
		
		for(i=2; i<N-2; i++){
			if(S[i] == '?') continue;
			
			for(j=0; j<2; j++){
				for(k=0; k<6; k++){ 
					if(S[i] != substring[j][(i+k)%6]) chk[j][k] = false;
				}
			}
		}
		
		ans = false;
		for(j=0; j<2; j++){
			for(k=0; k<6; k++){
				if(ans || !chk[j][k]) continue;
				for(i=2; i<N-2; i++){
					S_[i] = substring[j][(i+k)%6];
				}
				S_[0] = S[0];
				S_[1] = S[1];
				S_[N-2] = S[N-2];
				S_[N-1] = S[N-1];
				S_[N] = '\0';
				dfs(0);
			}
		}
		
		cout << "Case #" << C << ": ";
		if(ans || N<5){
			cout << POSSIBLE;
			continue;
		}
		cout << IMPOSSIBLE;
	}
	
	return 0;
}
