#include <stdio.h>

#define MAXN 110

using namespace std;

int wall[MAXN][MAXN];

int main()
{
	int t, n, m, i, j;
	
	scanf("%d", &t);
	while(t--){
		scanf("%d %d", &n, &m);
		for(i=1; i<=n; i++){
			for(j=1; j<=m; j++){
				scanf("%1d", &wall[i][j]);
			}
		}
		
		if(wall[1][1]){
			printf("-1\n");
			continue;
		}
		
		printf("%d\n", n*m-1);
		for(i=n; i>=1; i--){
			for(j=m; j>1; j--){
				if(wall[i][j]){
					printf("%d %d %d %d\n", i, j-1, i, j);
				}
				else{
					printf("%d %d %d %d\n", i, j, i, j);
				}
			}
		}
		for(i=n; i>1; i--){
			if(wall[i][j]){
				printf("%d %d %d %d\n", i-1, j, i, j);
			}
			else{
				printf("%d %d %d %d\n", i, j, i, j);
			}
		}
	}
	
	return 0;
}
