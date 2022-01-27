#include <stdio.h>
#include <string.h>

char str[2000001], str_[500], what['z'+1];
int when['z'+1];

void solve();

int main()
{
	setbuf(stdout, NULL);
	
	int T, C;
	
	scanf("%d", &T);
	for(C=1; C<=T; C++){
		printf("Case #%d\n", C);
		solve();
	}
	
	return 0;
}

void solve()
{
	int n, k, p, i, j, l;
	long long sum=0;
	
	scanf("%d %d", &n, &k);
	scanf("%s", str);
	for(p=1; p<=k; p++){
		scanf("%s", str_);
		l = strlen(str_);
		
		for(i='a'; i<='z'; i++) when[i] = -1;
		
		for(i=0; i<n-l+1; i++){
			for(j=0; j<l; j++){
				if(when[str_[j]] == i){
					if(what[str_[j]] == str[i+j]) continue;
					else break;
				}
				else{
					when[str_[j]] = i;
					what[str_[j]] = str[i+j];
				}
			}
			
			if(j<l) continue;
			sum += p;
		}
	}
	
	printf("%lld\n", sum);
}
