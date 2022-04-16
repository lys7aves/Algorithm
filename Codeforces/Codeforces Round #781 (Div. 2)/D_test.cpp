#include <bits/stdc++.h>

#define MAX 350
//1000000000

using namespace std;

long long random(){ return rand()*RAND_MAX + rand(); }

int gcd(int x, int y){ return y==0 ? x : gcd(y, x%y); }

int main()
{
	int ans, a, b, res;
	char x;
	
	ans = random() % MAX + 1;
	cout << ans << '\n';
	while(1){
		cin >> x >> a >> b;
		
		res = gcd(ans+a, ans+b);
		
		cout << res << '\n';
	}
	
	return 0;
}
