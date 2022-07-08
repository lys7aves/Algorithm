#include <bits/stdc++.h>

using namespace std;

int a[110][110], b[110][110];

int main()
{
	int n, m, k, i, j, l, x;
	
	scanf("%d %d", &n, &m);
	for(i=0; i<n; i++){
		for(j=0; j<m; j++){
			scanf("%d", &a[i][j]);
		}
	}
	
	scanf("%d %d", &m, &k);
	for(i=0; i<m; i++){
		for(j=0; j<k; j++){
			scanf("%d", &b[i][j]);
		}
	}
	
	for(i=0; i<n; i++){
		for(j=0; j<k; j++){
			x = 0;
			for(l=0; l<m; l++){
				x += a[i][l] * b[l][j];
			}
			printf("%d ", x);
		}
		printf("\n");
	}
	
	return 0;
}
