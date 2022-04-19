#include <bits/stdc++.h>

#define MAXN 500010

using namespace std;

int start;
int a[MAXN], dp[MAXN], tree[4*MAXN], tree0[4*MAXN];
long long sum[MAXN];
set<long long> s;
map<long long, int> renumber;

void insert(int i, int x);
int find_max(int i);
void insert0(int i, int x);
int find_max0(int i);
void clear();

int main()
{
	int t, n, i, number, tmp;
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> t;
	while(t--){
		s.clear();
		renumber.clear();
		
		cin >> n;
		for(i=1; i<=n; i++){
			cin >> a[i];
			sum[i] = sum[i-1] + a[i];
			s.insert(sum[i]);
		}
		s.insert(0);
		
		number = 0;
		for(auto i: s){
			renumber[i] = number++;
		}
		
		for(start=1; start<n; start*=2);
		clear();
		
		dp[0] = n;
		insert(renumber[0], n);
		insert0(renumber[0], 0);
		for(i=1; i<=n; i++){
			if(a[i] > 0) dp[i] = dp[i-1];
			if(a[i] == 0) dp[i] = dp[i-1] - 1;
			if(a[i] < 0) dp[i] = dp[i-1]-2;
			
			auto it = s.find(sum[i]);
			
			tmp = find_max0(renumber[*it]);
			tmp += n-i;
			
			dp[i] = max(dp[i], tmp);
			
			if(it != s.begin()){
				it--;
				tmp = find_max(renumber[*it]);
				
				dp[i] = max(dp[i], tmp);
			}
			
			insert(renumber[sum[i]], dp[i]);
			insert0(renumber[sum[i]], dp[i] - (n-i));
		}
		cout << dp[n] << '\n';
	}
	
	return 0;
}

void insert(int i, int x)
{
	i += start;
	
	tree[i] = max(tree[i], x);
	
	i /= 2;
	while(i){
		tree[i] = max(tree[i*2], tree[i*2+1]);
		i /= 2;
	}
}

void insert0(int i, int x)
{
	i += start;
	
	tree0[i] = max(tree0[i], x);
	
	i /= 2;
	while(i){
		tree0[i] = max(tree0[i*2], tree0[i*2+1]);
		i /= 2;
	}
}

int find_max(int i)
{
	int l=start;
	int maxi=-MAXN;
	
	i += start;
	while(i && l <= i){
		maxi = max(maxi, tree[i]);
		
		if(l == i) break;
		
		if(i%2 == 0) i--;
		i /= 2;
		l /= 2;
	}
	
	return maxi;
}

int find_max0(int i)
{
	int l=start;
	int maxi=-MAXN;
	
	i += start;
	while(i && l <= i){
		maxi = max(maxi, tree0[i]);
		
		if(l == i) break;
		
		if(i%2 == 0) i--;
		i /= 2;
		l /= 2;
	}
	
	return maxi;
}

void clear()
{
	for(int i=0; i<2*start; i++) tree[i] = tree0[i] = -MAXN;
}
