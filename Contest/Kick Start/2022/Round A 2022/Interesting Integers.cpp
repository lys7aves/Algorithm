#include <bits/stdc++.h>

using namespace std;

int solved(long long x)
{
	long long sum=0, product=1;
	
	while(x){
		sum += x%10;
		product *= x%10;
		x /= 10;
	}
	
	if(product % sum == 0) return 1;
	else return 0;
}

int main()
{
	int T, C;
	long long A, B, i, cnt;
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> T;
	for(C=1; C<=T; C++){
		cin >> A >> B;
		
		cnt = 0;
		for(i=A; i<=B; i++){
			cnt += solved(i);
		}
		
		cout << "Case #" << C << ": " << cnt << '\n';
	}
	
	return 0;
}
