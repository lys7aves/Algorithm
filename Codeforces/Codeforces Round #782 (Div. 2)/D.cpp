#include <bits/stdc++.h>

#define MAXN 200010

using namespace std;

int a[MAXN], c[MAXN], last[MAXN];

int main()
{
	int t, n, i, zeros;
	long long sum;
	
	cin >> t;
	while(t--){
		cin >> n;
		
		sum = 0;
		for(i=0; i<n; i++){
			cin >> c[i];
			sum += c[i];
			
			last[i] = a[i] = 0;
		}
		
		zeros = n - sum/n;
		for(i=zeros; i<n; i++){
			last[i] = n;
		}
		
		for(i=n-1; i>=0; i--){
			if(zeros == i+1) break;
			
			if(c[i] == last[i]-i) a[i] = 0;
			else a[i] = 1;
			
			if(a[i] == 0){
				zeros--;
				if(zeros>=0) last[zeros] = i;
			}
		}
		if(c[0] > 0) a[0] = 1;
		
		for(i=0; i<n; i++) cout << a[i] << ' ';
		cout << '\n';
	}
	
	return 0;
}
