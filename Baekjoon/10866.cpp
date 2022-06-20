#include <bits/stdc++.h>

using namespace std;

deque<int> deq;

int main()
{
	int n, x;
	string order;
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n;
	while(n--){
		cin >> order;
		
		if(order.compare("push_front") == 0){
			cin >> x;
			deq.push_front(x);
		}
		if(order.compare("push_back") == 0){
			cin >> x;
			deq.push_back(x);
		}
		if(order.compare("pop_front") == 0){
			if(deq.empty()) cout << "-1\n";
			else{
				cout << deq.front() << '\n';
				deq.pop_front();
			}
		}
		if(order.compare("pop_back") == 0){
			if(deq.empty()) cout << "-1\n";
			else{
				cout << deq.back() << '\n';
				deq.pop_back();
			}
		}
		if(order.compare("size") == 0){
			cout << deq.size() << '\n';
		}
		if(order.compare("empty") == 0){
			cout << deq.empty() << '\n';
		}
		if(order.compare("front") == 0){
			if(deq.empty()) cout << "-1\n";
			else cout << deq.front() << '\n';
		}
		if(order.compare("back") == 0){
			if(deq.empty()) cout << "-1\n";
			else cout << deq.back() << '\n';
		}
	}
	
	return 0;
}
