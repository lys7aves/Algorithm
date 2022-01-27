#include <stdio.h>

bool chk[5000000];
int diff[30];

int main()
{
	int k, n, i, j, l=0;
	
	scanf("%d %d", &k, &n);
	
	for(i=1; i<(5000000/2000); i++){
		for(j=1; j<=n; j++){
			if(chk[i*j]) break;
		}
		if(j <= n) continue;
		
		diff[l] = i;
		l++;
		
		if(l == n) break;
		
		for(j=1; j<=n; j++) chk[i*j] = true;
	}
	
	for(i=0; i<k; i++){
		for(j=0; j<n; j++) printf("%d ", 1+diff[i]*j);
		printf("\n");
	}
	
	return 0;
}
