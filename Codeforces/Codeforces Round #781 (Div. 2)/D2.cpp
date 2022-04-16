#include <bits/stdc++.h>

#define M (2*3*5*7*11*13*17*23*29)
#define MAXP 29
#define NUMP 9
#define MAX 1000000000

using namespace std;

int p[NUMP]={2,3,5,7,11,13,17,23,29};
int p_[NUMP];
int rest[NUMP];

void solve();
int CRT();

int main()
{
	int t, i, j;
	long long x;
	
	for(i=0; i<NUMP; i++){
		x = (M / p[i]) % p[i];
		for(j=1; j<p[i]; j++){
			if((x*j)%p[i] == 1){
				p_[i] = j;
				break;
			}
		}
	}
	
	cin >> t;
	while(t--){
		solve();
	}
	
	return 0;
}

void solve()
{
	int i, j, a, b, res, x, ans;
	
	for(i=0; i<NUMP; i++) rest[i] = 0;
	
	for(i=1; i<MAXP; i++){
		a = M+i;
		b = 2*M+i;
		
		cout << "? " << a << ' ' << b << '\n';
		cin >> res;
		
		for(j=0; j<NUMP; j++){
			if(res%p[j] == 0){
				rest[j] = (M-i) % p[j];
			}
		}
	}
	
	x = CRT();
	
	ans = x;
	for(i=1; M*i + x <= MAX; i++){
		a = M*i + x;
		b = a*2;
		
		cout << "? " << a << ' ' << b << '\n';
		cin >> res;
		
		if(res % a == 0) ans = a;
	}
	
	cout << "! " << ans << '\n';
}

int CRT()
{
	int i;
	long long x=0, A;
	
	for(i=0; i<NUMP; i++){
		A = M/p[i];
		A = (A * p_[i]) % M;
		A = (A * rest[i]) % M;
		x = (x + A) % M;
	}
	
	return x;
}
