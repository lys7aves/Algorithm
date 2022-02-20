#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> edge[200010];

struct NewNode{
	int num, cnt[3];
	
	char ori;
	int x;
};

bool cmp_cnt(const NewNode &x, const NewNode &y){
	int x_, y_;
	
	if(x.ori == 'R') x_ = x.cnt[1];
	else x_ = x.cnt[2];
	if(y.ori == 'R') y_ = y.cnt[1];
	else y_ = y.cnt[2];
	
	return x_ < y_;
}

bool cmp_num(const NewNode &x, const NewNode &y){
	return x.num < y.num;
}

bool flag=true;
NewNode ans[200010];

void dfs(int v);

int main()
{
	int n, m, t, i, j;
	
	scanf("%d %d", &n, &m);
	while(m--){
		scanf("%d %d %d", &t, &i, &j);
		edge[i].push_back(j);
		edge[j].push_back(i);
		
		ans[i].cnt[t]++;
		ans[j].cnt[t]++;
	}
	
	ans[1].ori = 'R';
	dfs(1);
	
	if(!flag){
		printf("NO");
		return 0;
	}
	
	for(i=1; i<=n; i++) ans[i].num = i;
	
	sort(ans, ans+n, cmp_cnt);
	
	for(i=1; i<=n; i++){
		ans[i].x = i;
	}
	
	sort(ans, ans+n, cmp_num);
	
	printf("YES\n");
	for(i=1; i<=n; i++){
		printf("%c %d\n", ans[i].ori, ans[i].x);
	}
	
	return 0;
}

void dfs(int v)
{
	for(int i=0; i<edge[v].size(); i++){
		int u = edge[v][i];
		
		if(ans[u].ori == 0){
			ans[u].ori = 'R'+'L' - ans[v].ori;
			dfs(u);
		}
		
		if(ans[u].ori != ans[v].ori) continue;
		else flag = false;
	}
}
