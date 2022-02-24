#include <stdio.h>

#define MAXN 500

bool chk[MAXN+1][MAXN+1];

int main()
{
	int T;
	
	scanf("%d", &T);
	for(int C=1; C<=T; C++){
		printf("Case #%d\n", C);
		
		int n, m, k, a, b;
		
		scanf("%d %d %d", &n, &m, &k);
		for(int i=1; i<=n; i++)
			for(int j=1; j<=n; j++)
				chk[i][j] = false;
		
		for(int i=0; i<m; i++){
			scanf("%d %d", &a, &b);
			chk[a][b] = true;
		}
		
		for(int l=1; l<=n; l++){
			for(int i=1; i<=n; i++){
				for(int j=1; j<=n; j++){
					chk[i][j] |= chk[i][l] & chk[l][j];
				}
			}
		}
		
		for(int i=0; i<k; i++){
			scanf("%d %d", &a, &b);
			if(chk[b][a]) printf("1");
			else{
				printf("0");
				
				if(chk[a][b]) continue;
				chk[a][b] = true;
				
				for(int j=1; j<=n; j++){
					for(int l=1; l<=n; l++){
						chk[j][b] |= chk[j][a];
						chk[a][l] |= chk[b][l];
						chk[j][l] |= chk[j][a] & chk[b][l];
					}
				}
			}
		}
		printf("\n");
	}
	
	return 0;
}
