#include <stdio.h>
#include <algorithm>

using namespace std;

int n, b, mini;
int h[20];

void dfs(int p, int q)
{
	if(p == n){
		if(q >= b){
			mini = min(mini, q-b);
		}
		return;
	}
	
	dfs(p+1, q);
	dfs(p+1, q+h[p]);
}

int main()
{
	int i;
	
	scanf("%d %d", &n, &b);
	for(i=0; i<n; i++){
		scanf("%d", &h[i]);
		mini += h[i];
	}
	
	dfs(0,0);
	
	printf("%d\n", mini);
	
	return 0;
}