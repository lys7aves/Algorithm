#include <iostream>
#include <algorithm>
#include <vector>

#define MAXN 100000

using namespace std;

int arr[MAXN];
vector<int> ans;

int main()
{
	int x, cnt=0, i, b, y, n;
	
	cin >> x;
	for(i=1; i*(i+2)<=x; i++){
		if(x%i == 0){
			ans.push_back(x/i-1);
		}
	}
	
	for(b=2; b*b<=x; b++){
		y = x;
		for(n=0; y; n++){
			arr[n] = y%b;
			y /= b;
		}
		
		for(i=0; i<n; i++){
			if(arr[i] != arr[n-i-1]) break;
		}
		
		if(i == n) ans.push_back(b);
	}
	
	sort(ans.begin(), ans.end());
	for(auto a: ans) cout << a << '\n';
	
	return 0;
}