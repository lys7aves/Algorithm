#include <bits/stdc++.h>

#define MAXF 100000

using namespace std;

unordered_map<string, int> num;
int parent[2*MAXF], cnt[2*MAXF];

int Union(int p1, int p2);
int Find(int p);

int main()
{
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);

	int T;
	cin >> T;
	
	while(T--){
		int f;
		cin >> f;
		
		while(f--){
			string p1, p2;
			int n1, n2;
			
			cin >> p1 >> p2;
			if(num.find(p1) == num.end()){
				num[p1] = f;
				parent[f] = f;
				cnt[f] = 1;
			}
			if(num.find(p2) == num.end()){
				num[p2] = f+MAXF;
				parent[f+MAXF] = f+MAXF;
				cnt[f+MAXF] = 1;
			}
			n1 = num[p1];
			n2 = num[p2];
			
			cout << Union(n1, n2) << '\n';
		}
		
		num.clear();
	}
	
	return 0;
}

int Union(int p1, int p2)
{
	int r1, r2;
	
	r1 = Find(p1);
	r2 = Find(p2);
	
	if(r1 != r2){
		parent[r2] = r1;
		cnt[r1] += cnt[r2];
	}
	
	return cnt[r1];
}

int Find(int p)
{
	return parent[p] == p ? p : (parent[p] = Find(parent[p]));
}
