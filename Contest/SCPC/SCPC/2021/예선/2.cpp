#include <stdio.h>

#define MAXN 50000

int A[MAXN], B[MAXN];

int main()
{
	int T;
	
	scanf("%d", &T);
	for(int C=1; C<=T; C++){
		int n, t;
		
		scanf("%d %d", &n, &t);
		for(int i=0; i<n; i++) A[i] = -1;
		
		for(int i=0; i<n; i++){
			scanf("%1d", &B[i]);
			if(B[i] == 0){
				if(i-t >= 0) A[i-t] = 0;
				if(i+t < n) A[i+t] = 0;
			}
		}
		
		for(int i=0; i<n; i++){
			if(B[i] == 0) continue;
			
			if(i-t < 0) A[i+t] = B[i];
			else if(i+t >= n) A[i-t] = B[i];
			else{
				if(A[i-t] == -1){
					if(A[i+t] == 0) A[i-t] = 1;
					else{
						A[i-t] = 0;
						A[i+t] = 1;
					}
				}
				else if(A[i-t] == 0) A[i+t] = 1;
			}
		}
		
		printf("Case #%d\n", C);
		for(int i=0; i<n; i++) printf("%d", A[i] == 1 ? 1 : 0);
		printf("\n");
	}
	
	return 0;
}
