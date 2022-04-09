#include <bits/stdc++.h>

#define P 10

using namespace std;

long long X=2*3*5*7*11*13*17*21*23;
int p[100]={2,3,5,7,11,13,17,21,23,29,};
long long M[100], M_[100];
int rest[100];

void solve();
int question(int a, int b);
int CRT();

int main()
{
	int t, i, j;
	
	for(i=0; i<10; i++) M[i] = X/p[i];
	for(i=0; i<10; i++){
		for(j=1; j<p[i]; j++){
			if((j*M[i])%p[i] == 1) M_[i] = j;
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
	int a, b, ret, i, j, ans;
	
	for(i=0; i<30; i++) rest[i] = -1;
	
	for(i=0; i<23; i++){
		a = X+i;
		b = 2*X+i;
		ret = question(a, b);
		
		for(j=0; j<10; j++){
			if(rest[j] != -1) continue;
			if(ret%p[j] == 0) rest[j] = i;
		}
	}
	
	ret = CRT();
	
	ans = 0;
	for(i=1; i<=5; i++){
		a = ret*i;
		if(a > 1000000000) break;
		
		int tmp = question(a, a*2);
		ans = max(ans, tmp);
	}
	
	cout << "! " << ans << '\n';
}

int question(int a, int b)
{
	int ret;
	
	cout << "? " << a << ' ' << b << '\n';
	cin >> ret;
	
	return ret;
}

int CRT()
{
	long long x=0, i;
	
	for(i=0; i<10; i++){
		cout << rest[i] << ' ';
	}
	
	return x;
}
