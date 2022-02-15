#include <stdio.h>
#include <algorithm>

#define MAXN 1010

using namespace std;

int a[MAXN][MAXN];

int main()
{
	while(1){
		int n=0, m=0, i, j, c, t;
		
		scanf("%d", &t);
		while(t--){
			scanf("%d %d %d", &i, &j, &c);
			a[i][j] = a[i][j+1] = a[i+1][j] = a[i+1][j+1] = c;
			
			n = max(n, i+1);
			m = max(m, j+1);
		}
		
		for(i=1; i<=n; i++){
			for(j=1; j<=m; j++){
				printf("%d ", a[i][j]);
				a[i][j] = 0;
			}
			printf("\n");
		}
	}
	
	return 0;
}
