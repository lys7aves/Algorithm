#include <iostream>
#include <stack>

using namespace std;

int p[510];
stack<int> s;

int main()
{
	int t, n, i, x;
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> t;
	while(t--){
		cin >> n;
		for(i=1; i<=n; i++){
			cin >> p[i];
		}
		
		for(i=1; i<=n; i++){
			if(p[i] != i) break;
			cout << p[i] << ' ';
		}
		
		x = i;
		for(; i<=n; i++){
			s.push(p[i]);
			if(p[i] == x) break;
		}
		
		while(!s.empty()){
			cout << s.top() << ' ';
			s.pop();
		}
		
		for(i=i+1; i<=n; i++){
			cout << p[i] << ' ';
		}
		
		cout << '\n';
	}
	
	return 0;
}
