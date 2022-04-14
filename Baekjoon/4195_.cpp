#include <iostream>
#include <string>
#include <map>

using namespace std;

map<string, string> parent;
map<string, int> cnt;

int Union(string p1, string p2);
string Find(string p);

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
			cin >> p1 >> p2;
			
			cout << Union(p1, p2) << '\n';
		}
		
		parent.clear();
		cnt.clear();
	}
	
	return 0;
}

int Union(string p1, string p2)
{
	string r1, r2;
	
	r1 = Find(p1);
	r2 = Find(p2);
	
	if(r1 != r2){
		parent[r2] = r1;
		cnt[r1] += cnt[r2];
	}
	
	return cnt[r1];
}

string Find(string p)
{
	if(parent.find(p) == parent.end()){
		parent[p] = p;
		cnt[p] = 1;
	}
	
	return parent[p] == p ? p : parent[p] = Find(parent[p]);
}
