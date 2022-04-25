#include <bits/stdc++.h>

using namespace std;

deque<int> dq;

int main()
{
	int T, C, n, i, d, prev, cnt;
	
	cin >> T;
	for(C=1; C<=T; C++){
		cin >> n;
		for(i=0; i<n; i++){
			cin >> d;
			dq.push_back(d);
		}
		
		prev = cnt = 0;
		while(!dq.empty()){
			if(dq.front() < dq.back()){
				d = dq.front();
				dq.pop_front();
			}
			else{
				d = dq.back();
				dq.pop_back();
			}
			
			if(d >= prev) cnt++;
			prev = max(prev, d);
		}
		
		cout << "Case #" << C << ": ";
		cout << cnt << '\n';
	}
	
	return 0;
}
