#include <bits/stdc++.h>

#define MAXE 110
#define MAXW 110

using namespace std;

int x[MAXE][MAXW], st[MAXE][MAXW], state[MAXE][MAXW];

int main()
{
	int T, C, e, w, i, j, k, top, ans, remove, remove_, pre_remove, total_pre_remove, add, mini=0, mini_idx, total;
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> T;
	for(C=1; C<=T; C++){
		cout << "Case #" << C << ": ";
		
		cin >> e >> w;
		for(i=1; i<=e; i++){
		}
		
		top = ans = 0;
		for(i=0; i<w; i++) st[0][i] = state[0][i] = 0;
		
		for(i=1; i<=e; i++){
			for(j=0; j<w; j++){
				cin >> x[i][j];
			}
			
			for(j=0; j<w; j++){
				if(state[top][j] > x[i][j]) break;
			}
			if(j == w){
				top++;
				for(j=0; j<w; j++){
					state[top][j] = x[i][j];
					ans += state[top][j] - state[top-1][j];
				}
				continue;
			}
			
			for(k=top; k>0; k--){
				for(j=0; j<w; j++){
					if(state[k][j] > x[i][j]) break;
				}
				if(j == w) break;
			}
			
			int k_ = ++k;
			pre_remove = total_pre_remove = 0;
			mini = 2000000000;
			for(k; k<=top; k++){
				remove = 0;
				for(j=0; j<w; j++) remove += state[top][j] - state[k][j];
				
				remove_ = 0;
				for(j=0; j<w; j++) remove_ += state[k][j] - x[i][j];
				
				add = 0;
				for(j=0; j<w; j++){
					if(x[i][j] > state[k][j]) add += x[i][j] - state[k][j];
				}
				
				total = remove + remove_ + total_pre_remove + add;
				
				if(total < mini){
					mini = total;
					mini_idx = k;
				}
				
				pre_remove += remove_;
				total_pre_remove += 2*pre_remove;
			}
			
			ans += mini;
			top = k+1;
			for(k; k>=k_; k--){
				for(j=0; j<w; j++){
					state[k][j] = min(state[k][j], x[i][j]);
				}
			}
			for(j=0; j<w; j++){
				state[top][j] = x[i][j];
			}
		}
		
		for(i=0; i<w; i++) ans += state[top][i];
		
		cout << ans << '\n';
	}
	
	return 0;
}
