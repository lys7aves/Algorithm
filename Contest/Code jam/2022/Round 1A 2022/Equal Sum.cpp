#include <bits/stdc++.h>

#define MAX 1000000000

using namespace std;

int A[110], B[110];

int main()
{
	int t, n, i;
	long long sum;
	
	cin >> t;
	while(t--){
		cin >> n;
		
		for(i=0; i<min(30,n); i++) A[i] = 1<<i;
		for(; i<n; i++) A[i] = MAX - (i-30);
		
		sum = 0;
		for(i=0; i<n; i++){
			cout << A[i] << ' ';
			sum += A[i];
		}
		cout << '\n';
		
		for(i=0; i<n; i++){
			cout << B[i];
			sum += B[i];
		}
	}
	
	return 0;
}
