#include <iostream>

using namespace std;

int main()
{
	int t, cnt, i;
	long long x, d;
	bool prime_x, prime_d;
	
	cin >> t;
	while(t--){
		cin >> x >> d;
		
		for(cnt=0; x%d==0; cnt++) x /= d;
		
		prime_x = true;
		for(i=2; i*i<=x; i++){
			if(x%i == 0) prime_x = false;
		}
		prime_d = true;
		for(i=2; i*i<=d; i++){
			if(d%i == 0) prime_d = false;
		}
		
		if(cnt == 1) printf("NO\n");
		else if(!prime_x) printf("YES\n");
		else if(prime_d) printf("NO\n");
		else if(cnt == 2) printf("NO\n");
		else if(cnt >= 4) printf("YES\n");
		else if(d == x*x) printf("NO\n");
		else printf("YES\n");
	}
	
	return 0;
}
