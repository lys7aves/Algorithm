#include <iostream>
#include <algorithm>
 
#define MOD 1000000007
 
using namespace std;
 
struct BaseNum{
	int base, num;
	
	bool operator<(BaseNum x){
		if(base != x.base) return base < x.base;
		return num < x.num;
	}
};
 
BaseNum a[200010];
int fibo[200010], s_fibo[200010];
 
void init();
int base_number(int x);
 
int main()
{
	int n, p, i, k, ans=0;
	
	init();
	
	cin >> n >> p;
	for(i=0; i<n; i++){
		cin >> a[i].num;
		a[i].base = base_number(a[i].num);
	}
	
	sort(a, a+n);
	
	for(i=0; i<n; i++){
		if(i && a[i].base == a[i-1].base) continue;
		
		for(k=0; (1<<k) <= a[i].num; k++);
		
		if(p-k >= 0) ans = (ans + s_fibo[p-k]) % MOD;
	}
	
	cout << ans;
	
	return 0;
}
 
void init()
{
	int i;
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	fibo[0] = fibo[1] = 1;
	s_fibo[0] = 1;
	s_fibo[1] = 2;
	for(i=2; i<=200000; i++){
		fibo[i] = (fibo[i-1] + fibo[i-2]) % MOD;
		s_fibo[i] = (s_fibo[i-1] + fibo[i]) % MOD;
	}
}
 
int base_number(int x)
{
	if(x == 1) return 1;
	if(x%2 == 1) return base_number(x/2);
	if(x%4 == 0) return base_number(x/4);
	return x;
}
