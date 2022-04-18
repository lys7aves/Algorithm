#include <bits/stdc++.h>

#define MAXN 200010

using namespace std;

long long x[MAXN];

int main()
{
	int t, n, a, b, i;
	long long mini, sum, cost;
	
	cin >> t;
	while(t--){
		cin >> n >> a >> b;
		for(i=1; i<=n; i++){
			cin >> x[i];
		}
		
		mini = x[n] * (a+b);
		sum = 0;
		for(i=1; i<=n; i++){
			sum += (x[n-i+1] - x[n-i]) * i;
			cost = x[n-i] * (a+b) + sum * b;
			
			mini = min(mini, cost);
		}
		
		cout << mini << '\n';
	}
	
	return 0;
}
