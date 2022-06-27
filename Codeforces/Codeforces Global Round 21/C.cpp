#include <bits/stdc++.h>

using namespace std;

deque<int> a, b;

int main()
{
	int t, n, m, k, i, x, y;
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> t;
	while(t--){
		cin >> n >> m;
		while(n--){
			cin >> x;
			a.push_back(x);
			a.push_back(1);
		}
		cin >> k;
		while(k--){
			cin >> x;
			b.push_back(x);
			b.push_back(1);
		}
		
		while(!a.empty() && !b.empty()){
			//cout << a.front() << ' ' << b.front() << ' ' << a.size() << ' ' << b.size() << '\n';
			if(a.front() == b.front()){
				x = a.front();
				a.pop_front();
				b.pop_front();
				
				if(a.front() == b.front()){
					a.pop_front();
					b.pop_front();
				}
				else if(a.front() > b.front()){
					y = a.front() - b.front();
					a.pop_front();
					b.pop_front();
					
					a.push_front(y);
					a.push_front(x);
				}
				else{
					y = b.front() - a.front();
					a.pop_front();
					b.pop_front();
					
					b.push_front(y);
					b.push_front(x);
				}
			}
			else if(a.front() > b.front()){
				x = a.front();
				a.pop_front();
				
				if(a.front() == 1) a.pop_front();
				else{
					y = a.front();
					a.pop_front();
					
					a.push_front(y-1);
					a.push_front(x);
				}
				
				if(x%m != 0) break;
				a.push_front(m);
				a.push_front(x/m);
			}
			else{
				x = b.front();
				b.pop_front();
				
				if(b.front() == 1) b.pop_front();
				else{
					y = b.front();
					b.pop_front();
					
					b.push_front(y-1);
					b.push_front(x);
				}
				
				if(x%m != 0) break;
				b.push_front(m);
				b.push_front(x/m);
			}
		}
		
		if(a.empty() && b.empty()) cout << "Yes\n";
		else cout << "No\n";
		
		while(!a.empty()) a.pop_front();
		while(!b.empty()) b.pop_front();
	}
	
	return 0;
}
