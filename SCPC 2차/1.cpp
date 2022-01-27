#include <stdio.h>
#include <math.h>

int main()
{
	int T, C;
	
	scanf("%d", &T);
	for(C=1; C<=T; C++){
		long long r, x, y, cnt=0;
		scanf("%lld", &r);
		
		for(x=0; x<r; x++){
			cnt += sqrt(r*r-x*x-1);
		}
		
		printf("Case #%d\n", C);
		printf("%lld\n", cnt*4+1);
	}
	
	return 0;
}
