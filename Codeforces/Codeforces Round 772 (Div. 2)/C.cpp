#include <stdio.h>

int a[200010];

int main()
{
	int t, n, i;
	bool inc;
	
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		
		inc = true;
		for(i=0; i<n; i++){
			scanf("%d", &a[i]);
			if(i && a[i]<a[i-1]) inc = false;
		}
		
		if(inc){
			printf("0\n");
			continue;
		}
		
		if(a[n-1] < a[n-2] || a[n-1] < 0){
			printf("-1\n");
			continue;
		}
		
		printf("%d\n", n-2);
		for(i=0; i<n-2; i++) printf("%d %d %d\n", i+1, n-1, n);
	}
	
	return 0;
}
