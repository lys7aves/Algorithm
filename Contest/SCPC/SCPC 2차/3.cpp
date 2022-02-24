#include <stdio.h>
#include <algorithm>

#define K 1200
#define MAX 3000

using namespace std;

int board[MAX][MAX];
long long sum[MAX][MAX], sum_[MAX][MAX], suml[MAX][MAX];

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
	int n, k, i, j, l;
	
	scanf("%d %d", &n, &k);
	for(i=0+K; i<n+K; i++){
		for(j=0+K; j<n+K; j++){
			scanf("%d", &board[i][j]);
		}
	}
	
	for(i=K; i<K+n+2*k; i++){
		for(j=K+n; j>=K-2*k; j--)
			sum[i][j] = sum[i-1][j+1] + board[i][j];
		for(j=K; j<K+n+2*k; j++){
			sum_[i][j] = sum_[i-1][j-1] + board[i][j];
			suml[i][j] = suml[i-1][j] + board[i][j];
		}
	}
	
	long long maxi=0;
	for(i=K-k; i<K+n+k; i++){
		long long S=0, s1=0, s2=0;
		
		for(j=K-k; j<K+n+k; j++){
			s2 += (sum[i+k-1][j+1]-sum[i][j+k]) + (sum_[i][j+k]-sum_[i-k][j]) - (suml[i+k-1][j]-suml[i-k][j]);
			S = S-s1+s2;
			s1 -= (sum_[i+k-1][j]-sum_[i][j-k+1]) + (sum[i][j-k+1]-sum[i-k][j+1]) - (suml[i+k-1][j+1]-suml[i-k][j+1]);
			
			maxi = max(maxi, S);
		}
	}
	
	printf("%lld\n", maxi);
	
	for(i=K; i<n+K; i++)
		for(j=K; j<n+K; j++)
			board[i][j] = 0;
	
	for(i=K; i<K+n+2*k; i++){
		for(j=K+n; j>=K-2*k; j--)
			sum[i][j] = 0;
		for(j=K; j<K+n+2*k; j++){
			sum_[i][j] = 0;
			suml[i][j] = 0;
		}
	}
}
