#include <bits/stdc++.h>

using namespace std;

bool V[8];
bool solve();

int main()
{
	int T;
	
	srand(time(NULL));
	
	cin >> T;
	while(T--){
		if(!solve()) break;
	}
	
	return 0;
}

bool solve()
{
	int x=1, i;
	
	while(1){
		for(i=0; i<8; i++) V[i] = 0;
		while(x--){
			do{
				i = rand()%8;
			}while(V[i]);
			V[i] = 1;
		}
		
		for(i=0; i<8; i++) cout << V[i];
		cout << '\n';
		cin >> x;
		
		if(x == 0) return true;
		else if(x == 8){
			cout << "11111111\n";
			cin >> x;
			return true;
		}
		else if(x == -1) return false;
		else{
			x = min(x, 8-x);
		}
	}
}
