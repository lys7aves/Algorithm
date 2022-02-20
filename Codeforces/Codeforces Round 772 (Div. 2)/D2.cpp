#include <iostream>
#include <algorithm>
#include <unordered_set>

#define MOD 1000000007

using namespace std;

int a[200010], fibo[200010], s_fibo[200010];
unordered_set<int> s;

void init();
bool check_number(int x);

int main()
{
	int n, p, i, k, ans=0;
	
	init();
	
	cin >> n >> p;
	for(i=0; i<n; i++){
		cin >> a[i];
	}
	
	sort(a, a+n);
	for(i=0; i<n; i++){
		if(check_number(a[i])){
			s.insert(a[i]);
		}
	}
	
	for(auto it=s.begin(); it!=s.end(); it++){
		
		for(k=0; (1<<k) <= *it; k++);
		//cout << k << '\n';
		
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

bool check_number(int x)
{
	if(s.find(x) != s.end()) return false;
	
	if(x == 1) return true;
	if(x%2 == 1) return check_number(x/2);
	if(x%4 == 0) return check_number(x/4);
	return true;
}
