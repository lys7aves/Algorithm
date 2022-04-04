#include <bits/stdc++.h>

#define pii pair<int,int>

#define MAXN 100010

using namespace std;

vector<pii> rand_order;
int P[MAXN], max_walk[MAXN];
set<int> edge[MAXN];

int random_number(){ return rand()*RAND_MAX + rand(); }

int main()
{
	int T, n, k, r, p, prev_r, i, j, cnt;
	double pr, sum, sum_;
	long long ans;
	pii tmp;
	
	srand(time(NULL));
	for(i=1; i<=100000; i++){
		pr = 1;
		for(j=0; j<i; j++){
			pr *= (i-j)/(double)i;
			
			if(pr < 0.5) break;
		}
		max_walk[i] = j;
	}
	
	cin >> T;
	while(T--){
		cin >> n >> k;
		
		rand_order.clear();
		for(i=1; i<=n; i++){
			P[i] = 0;
			edge[i].clear();
			
			tmp.first = random_number();
			tmp.second = i;
			
			rand_order.push_back(tmp);
		}
		sort(rand_order.begin(), rand_order.end());
		
		cin >> r >> p;
		P[r] = p;
		
		prev_r = r;
		i = 0;
		while(k--){
			if(edge[prev_r].size() < max_walk[P[prev_r]]){
				cout << "W\n" << flush;
				cin >> r >> p;
				
				edge[r].insert(prev_r);
				edge[prev_r].insert(r);
			}
			else{
				for(; i<n; i++){
					r = rand_order[i].second;
					if(P[r]) continue;
					
					cout << "T " << r << '\n' << flush;
					cin >> r >> p;
					
					break;
				}
			}
			
			P[r] = p;
			prev_r = r;
		}
		
		sum = 0;
		for(i=1; i<=n; i++){
			if(P[i] == 0) continue;
			
			if(edge[i].size() == 0){
				sum += P[i];
				cnt++;
				continue;
			}
			
			sum_ = 0;
			for(auto it=edge[i].begin(); it!=edge[i].end(); it++){
				r = *it;
				sum_ += P[r]/edge[r].size();
			}
			//cout << i << ' ' << P[i] << ' ' << ' ' << edge[i].size() << ' ' << sum_ << '\n';
			sum += sum_ * P[i] / edge[i].size();
			cnt += P[i];
			cnt -= edge[i].size()-1;
		}
		//cout << sum << ' ' << cnt << '\n';
		
		ans = sum * n / cnt / 2;
		
		cout << "E " << ans << '\n' << flush;
		
		rand_order.clear();
	}
	
	return 0;
}
