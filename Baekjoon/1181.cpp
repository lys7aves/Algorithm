#include <bits/stdc++.h>

using namespace std;

string str[20010];

bool cmp(const string &x, const string &y){
	if(x.size() != y.size()) return x.size() < y.size();
	else return x.compare(y) < 0;
}

int main()
{
	int n, i;
	
	cin >> n;
	for(i=0; i<n; i++){
		cin >> str[i];
	}
	
	sort(str, str+n, cmp);
	
	for(i=0; i<n; i++){
		if(i && str[i].compare(str[i-1]) == 0) continue;
		cout << str[i] << '\n';
	}
	
	return 0;
}
