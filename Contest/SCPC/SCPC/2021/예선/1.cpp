#include <stdio.h>

#define MAXN 100000

int p[MAXN];
bool chk[MAXN];

void Union(int u, int v);
int Find(int v);

int main()
{
	int T;
	
	scanf("%d", &T);
	for(int C=1; C<=T; C++){
		int n, d, cnt=0;
		
		scanf("%d", &n);
		
		for(int i=0; i<n; i++){
			p[i] = i;
			chk[i] = false;
		}
		
		for(int i=0; i<n; i++){
			scanf("%d", &d);
			if(i+d < n) Union(i, i+d);
		}
		
		for(int i=0; i<n; i++){
			if(chk[Find(i)]) continue;
			chk[p[i]] = true;
			
			cnt++;
		}
		
		printf("Case #%d\n", C);
		printf("%d\n", cnt);
	}
	
	return 0;
}

void Union(int u, int v)
{
	p[Find(v)] = Find(u);
}

int Find(int v)
{
	return p[v] == v ? v : (p[v] = Find(p[v]));
}
