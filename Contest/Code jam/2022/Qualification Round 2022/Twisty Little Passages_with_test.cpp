#include <bits/stdc++.h>

#define pii pair<int,int>
#define MAXT 100
#define MAXN 100000
#define MAXK 8000
#define TEST true

using namespace std;

vector<pii> rand_order;
set<int> _edge[MAXN+1];

int* input();
void output();

int main()
{
	int T, n, k, r, p, i;
	int* ret;
	long long sum, ans;
	
	srand(time(NULL));
	
	ret = input();
	T = ret[0];
	
	while(T--){
		cin >> n >> k;
		cin >> r >> p;
		
		for(i=1; i<=n; i++){
			if(i == r) continue;
			
			pii tmp;
			tmp.first = rand()*rand();
			tmp.second = i;
			
			rand_order.push_back(tmp);
		}
		
		sort(rand_order.begin(), rand_order.end());
		
		sum = p;
		for(i=0; i<min(k, n-1); i++){
			cout << "T " << rand_order[i].second << '\n' << flush;
			cin >> r >> p;
			
			sum += p;
		}
		
		ans = sum * n / 2.0 / min(k+1, n) + 0.5;
		if(ans < n-1) ans = n-1;
		if(ans > ((long long)n) * (n-1) / 2) ans = ((long long)n) * (n-1) / 2;
		
		cout << "E " << ans << '\n' << flush;
		
		rand_order.clear();
	}
	
	return 0;
}

int* input()
{
	static int ret[2], T=rand()%MAXT, C=0, K;
	static long long N, P;
	static bool start=true, round_start=true;
	int i;
	
#if TEST == true
	if(start){
		ret[0] = T;
		start = false;
	}
	else{
		if(round_start){
			N = rand()%MAXN;
			P = (long long)rand()*rand()*rand()%(N*(N-1)/2);
			
			for(i=1; i<=N; i++) _edge[i].clear();
			for(i=0; i<P; i++){
				int u, v;
				u = rand()%N+1;
				v = rand()%N+1;
				if(_edge[u].find(v) != _edge[u].end()){
					u = rand()%N+1;
					v = rand()%N+1;
				}
				_edge[u].insert(v);
				_edge[v].insert(u);
			}
			
			int R = rand()%N+1;
			
			ret[0] = R;
			ret[1] = _edge[R].size();
		}
		else{
		}
	}
	

#else
	cin << ret[0];

#endif
	return ret;
}

void output()
{
}
