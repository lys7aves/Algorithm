#include <stdio.h>
#include <algorithm>

#define MAXN 20000
#define MAXM 50000

using namespace std;

struct w4{
	int w[4];
	int l;
};

bool cmp(const w4 &x, const w4 &y){
	return x.w[2]+x.w[3] > y.w[2]+y.w[3];
}

w4 w[MAXN];
int w_[2*MAXM];

int main()
{
	int T;
	
	scanf("%d", &T);
	for(int C=1; C<=T; C++){
		int n, m, l, odd=0;
		long long penalty=0;
		
		scanf("%d %d", &n, &m);
		for(int i=0; i<n; i++){
			scanf("%d", &l);
			for(int j=0; j<l; j++)
				scanf("%d", &w_[j]);
			sort(w_, w_+l);
			
			for(int j=0; j<4; j++)
				penalty += (w[i].w[j] = w_[j]);
			
			odd += (w[i].l = l%2);
			if(l%2 == 1) penalty += w_[0];
		}
		
		sort(w, w+n, cmp);
		
		if(odd == 2 && n != 2){
			if(w[0].l == 1 && w[1].l == 1){
				long long advantage1, advantage2;
				
				advantage1 = w[0].w[2] + w[0].w[3] + w[2].w[2] + w[2].w[3];
				
				advantage2 = w[0].w[2] + w[0].w[3] + w[1].w[2] + w[1].w[3];
				for(int i=2; i<n; i++){
					advantage2 -= w[i].w[0] + w[i].w[1];
				}
				
				penalty -= max(advantage1, advantage2);
			}
			else{
				penalty -= w[0].w[2] + w[0].w[3] + w[1].w[2] + w[1].w[3];
			}
		}
		else{
			penalty -= w[0].w[2] + w[0].w[3] + w[1].w[2] + w[1].w[3];
		}
		
		printf("Case #%d\n", C);
		printf("%lld\n", penalty);
	}
	
	return 0;
}
