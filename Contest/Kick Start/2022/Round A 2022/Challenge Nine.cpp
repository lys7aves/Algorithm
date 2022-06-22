#include <bits/stdc++.h>

using namespace std;

int main()
{
	int T, C, i, sum, need_number;
	string N;
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> T;
	for(C=1; C<=T; C++){
		cin >> N;
		
		sum = 0;
		for(i=0; i<N.size(); i++){
			sum += N[i] - '0';
		}
		need_number = (9 - (sum%9)) % 9;
		
		cout << "Case #" << C << ": ";
		i = 0;
		if(need_number == 0){
			i = 1;
			cout << N[0];
		}
		for(; i<N.size(); i++){
			if(need_number < N[i]-'0') break;
			cout << N[i];
		}
		cout << need_number;
		for(; i<N.size(); i++){
			cout << N[i];
		}
		cout << '\n';
	}
	
	return 0;
}
