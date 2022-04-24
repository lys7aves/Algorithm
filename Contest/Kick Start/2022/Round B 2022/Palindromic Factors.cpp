#include <bits/stdc++.h>

using namespace std;

bool is_palindrome(long long x);

int main()
{
	int T, C, cnt;
	long long i, a;
	
	cin >> T;
	for(C=1; C<=T; C++){
		cin >> a;
		
		cnt = 0;
		for(i=1; i*i<=a; i++){
			if(a%i == 0){
				if(is_palindrome(i)) cnt++;
				if(i != a/i && is_palindrome(a/i)) cnt++;
			}
		}
		
		cout << "Case #" << C << ": ";
		cout << cnt << '\n';
	}
	
	return 0;
}

bool is_palindrome(long long x)
{
	int i;
	vector<int> arr;
	
	while(x){
		arr.push_back(x%10);
		x /= 10;
	}
	
	for(i=0; i<arr.size(); i++){
		if(arr[i] != arr[arr.size()-i-1]) return false;
	}
	return true;
}
