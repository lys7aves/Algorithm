#include <stdio.h>

#define MAXN 100000

int p[MAXN+1], diff[MAXN+1];
bool CF[MAXN+1];

void Union(int v, int u, int d);
int Find(int v);

int main()
{
	int T;
	
	scanf("%d", &T);
	for(int C=1; C<=T; C++){
		printf("Case #%d\n", C);
		
		int n, k, x, v, u, d;
		
		scanf("%d %d", &n, &k);
		
		for(int i=1; i<=n; i++){
			p[i] = i;
			diff[i] = 0;
			CF[i] = false;
		}
		
		while(k--){
			scanf("%d", &x);
			
			if(x == 1){
				scanf("%d %d %d", &v, &u, &d);
				Union(v, u, d);
			}
			else{
				scanf("%d %d", &v, &u);
				Find(v);
				Find(u);
				
				if(p[v] == p[u]){
					if(CF[p[v]] == true) printf("CF\n");
					else printf("%d\n", diff[v] - diff[u]);
				}
				else printf("NC\n");
			}
		}
	}
	
	return 0;
}

void Union(int v, int u, int d)
{
	Find(v);
	Find(u);
	
	if(p[v] == p[u]){
		if(diff[v]-diff[u] == d) return;
		else CF[p[v]] = true;
	}
	else{
		diff[p[v]] = d - diff[v] + diff[u];
		CF[p[u]] |= CF[p[v]];
		p[p[v]] = p[u];
	}
}

int Find(int v)
{
	if(p[v] == v) return v;
	
	CF[p[v]] |= CF[v];
	int P = Find(p[v]);
	diff[v] += diff[p[v]];
	
	return p[v] = P;
}
