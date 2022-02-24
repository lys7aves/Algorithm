#include <stdio.h>
#include <algorithm>

using namespace std;

long long k, mini;

int x[8], y[8], seq[8];
long long dx[8], dy[8];
bool chk[8];

int stdx[8]={0,0,1,2,3,3,2,1};
int stdy[8]={1,2,3,3,2,1,0,0};

void dfs(int p);
void check();

int main()
{
	int T, C;
	
	scanf("%d", &T);
	for(C=1; C<=T; C++){
		scanf("%d", &k);
		for(int i=0; i<8; i++){
			scanf("%d %d", &x[i], &y[i]);
		}
		
		mini = 3200000000;
		dfs(0);
		
		printf("Case #%d\n", C);
		printf("%lld\n", mini);
	}
	
	return 0;
}

void dfs(int p)
{
	if(p == 8) check();
	
	for(int i=0; i<8; i++){
		if(chk[i]) continue;
		seq[p] = i;
		chk[i] = true;
		dfs(p+1);
		chk[i] = false;
	}
}

void check()
{
	long long sum=0, x4, y4;
	
	for(int i=0; i<8; i++){
		dx[i] = stdx[i]*k - x[seq[i]];
		dy[i] = stdy[i]*k - y[seq[i]];
		
	}
	
	sort(dx, dx+8);
	sort(dy, dy+8);
	
	x4 = dx[4];
	y4 = dy[4];
	for(int i=0; i<8; i++){
		dx[i] -= x4;
		dy[i] -= y4;
		
		sum += abs(dx[i]) + abs(dy[i]);
	}
	
	mini = min(mini, sum);
}
