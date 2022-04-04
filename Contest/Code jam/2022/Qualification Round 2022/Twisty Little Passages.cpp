#include <bits/stdc++.h>

#define pli pair<int,int>

#define MAXN 100010

using namespace std;

vector<pli> rand_order;

long long random_number(){ return (long long)rand()*RAND_MAX + rand(); }

int main()
{
	int T, r, p, p_, i;
	long long n, k, sum, ans;
	
	srand(time(NULL));
	
	cin >> T;
	while(T--){
		cin >> n >> k;
		cin >> r >> p_;
		
		for(i=1; i<=n; i++){
			pli tmp;
			tmp.first = random_number();
			tmp.second = i;
			
			rand_order.push_back(tmp);
		}
		
		sort(rand_order.begin(), rand_order.end());
		
		sum = 0;
		for(i=0; i<min(k, n); i++){
			cout << "T " << rand_order[i].second << '\n' << flush;
			cin >> r >> p;
			
			sum += p;
		}
		for(; i<k; i++){
			cout << "W\n" << flush;
			cin >> r >> p;
		}
		
		ans = sum * n / 2.0 / min(k, n) + 0.5;
		
		cout << "E " << ans << '\n' << flush;
		
		rand_order.clear();
	}
	
	return 0;
}
