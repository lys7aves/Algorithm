#include <bits/stdc++.h>

using namespace std;

map<string, int> name2num;
map<int, string> num2name;

int main()
{
	int n, m, i;
	string str;
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n >> m;
	for(i=0; i<n; i++){
		cin >> str;
		name2num[str] = i+1;
		num2name[i+1] = str;
	}
	
	while(m--){
		cin >> str;
		if(str[0] >= '0' && str[0] <= '9'){
			i = stoi(str);
			cout << num2name[i] << '\n';
		}
		else{
			cout << name2num[str] << '\n';
		}
		
	}
	
	return 0;
}
