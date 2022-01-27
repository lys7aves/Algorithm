#include <stdio.h>

int main()
{
	int a, i;
	double d, k, r=1, sum=0;
	
	scanf("%d %lf %lf", &a, &d, &k);
	d /= 100;
	k /= 100;
	
	for(i=1; d<1; i++){
		sum += r*d*a*i;
		r *= (1-d);
		d *= (1+k);
	}
	sum += r*a*i;
	
	printf("%.7lf", sum);
	
	return 0;
}
