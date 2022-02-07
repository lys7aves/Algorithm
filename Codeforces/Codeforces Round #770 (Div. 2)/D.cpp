#include <iostream>

#define MAXN 1000

using namespace std;

int d_01[MAXN], d_0x[MAXN], d_1xy;

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int t, n, i, x, y, maxi, a, b;
	
	cin >> t;
	while(t--){
		cin >> n;
		
		for(i=2; i<n; i++){
			cout << "? 0 1 " << i << '\n';
			cout.flush();
			cin >> d_01[i];
		}
		
		x = 2;
		for(i=2; i<n; i++){
			if(d_01[i] > d_01[x]) x = i;
		}
		
		d_0x[1] = d_01[x];
		for(i=2; i<n; i++){
			if(x == i) continue;
			
			cout << "? 0 " << x << ' ' << i << '\n';
			cout.flush();
			cin >> d_0x[i];
		}
		
		for(i=2; i<n; i++){
			if(i == x) continue;
			if(d_0x[i] > d_0x[y]) y = i;
		}
		
		cout << "? 1 " << x << ' ' << y << '\n';
		cout.flush();
		cin >> d_1xy;
		
		maxi = max(d_01[x], max(d_01[y], max(d_0x[y], d_1xy)));
		
		if(d_01[x] == maxi && d_01[y] == maxi) cout << "! 0 1\n";
		else if(d_01[x] == maxi && d_0x[y] == maxi) cout << "! 0 " << x << '\n';
		else if(d_01[y] == maxi && d_0x[y] == maxi) cout << "! 0 " << y << '\n';
		else if(d_01[x] == maxi && d_1xy == maxi) cout << "! 1 " << x << '\n';
		else if(d_01[y] == maxi && d_1xy == maxi) cout << "! 1 " << y << '\n';
		else if(d_0x[y] == maxi && d_1xy == maxi) cout << "! " << x << ' ' << y << '\n';
		cout.flush();
	}
	
	return 0;
}
