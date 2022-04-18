#include <bits/stdc++.h>

#define MAXN 100010

using namespace std;

int p[30][MAXN], p1[30][MAXN];
bool non_one[MAXN];

void Union(int k, int u, int v);
int Find(int k, int v);

int main()
{
	int n, m, i, j, a, b, w, q;
	bool flag;
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n >> m;
	
	for(i=0; i<30; i++){
		for(j=1; j<=n; j++){
			p[i][j] = j;
		}
	}
	
	while(m--){
		cin >> a >> b >> w;
		for(i=0; i<30; i++){
			if((w&(1<<i)) > 0){
				Union(i, a, b);
			}
		}
		
		if((w&1) == 0) non_one[a] = non_one[b] = true;
		else{
		}
	}
	
	cin >> q;
	while(q--){
		cin >> a >> b;
		
		flag = false;
		for(i=0; i<30; i++){
			if(Find(i,a) == Find(i,b)) flag = true;
		}
		
		if(flag){
			cout << "0\n";
		}
		else{
			cout << "2\n";
		}
	}
	
	return 0;
}

void Union(int k, int u, int v)
{
	int pu, pv;
	
	pu = Find(k, u);
	pv = Find(k, v);
	
	p[k][pu] = pv;
}

int Find(int k, int v)
{
	return p[k][v] = (p[k][v] == v ? v : Find(k, p[k][v]));
}
