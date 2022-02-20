#include <iostream>
#include <stack>

using namespace std;

bool broken[10];
int num[10];

int main()
{
	int n, n_, m, i, j, k, x, ans, cnt;
	int upper=0, lower=0, min_num=9, min_num_=999, max_num=0, u_n, l_n;
	bool flag;
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	// Input
	cin >> n;
	cin >> m;
	for(i=0; i<m; i++){
		cin >> x;
		broken[x] = true;
	}
	
	// Only use + or - buttons
	ans = abs(n - 100);
	if(m == 10){
		cout << ans;
		return 0;
	}
	
	// Devide n
	n_ = n;
	for(i=0; n; i++){
		num[i] = n%10;
		n /= 10;
	}
	// Now n means previous n's length.
	n = u_n = l_n = i;
	
	// Find minimum number and maximum number which are not broken
	for(i=0; i<10; i++){
		if(!broken[i]){
			min_num = min(min_num, i);
			max_num = i;
			if(i) min_num_ = min(min_num_, i);
		}
	}
	
	// Find upper and lower number
	for(i=n-1; i>=0; i--){
		if(flag){
			upper = upper*10 + min_num;
			lower = lower*10 + max_num;
			continue;
		}
		
		if(broken[num[i]]){
			// Find minimum number which is not broken and bigger than num[i]
			for(j=num[i]; j<10 && broken[j]; j++);
			if(j < 10){
				upper = upper*10 + j;
			}
			else{
				cnt = 1;
				while(upper){
					x = upper%10;
					upper /= 10;
					
					for(j=x+1; j<10 && broken[j]; j++);
					if(j < 10){
						upper = upper*10 + j;
						break;
					}
					
					cnt++;
				}
				if(upper == 0){
					upper = min_num_;
					u_n++;
				}
				while(cnt--) upper = upper*10 + min_num;
			}
			
			// Find maximum number which is not broken and smaller than num[i]
			for(j=num[i]; j>=0 && broken[j]; j--);
			if(j >= 0){
				lower = lower*10 + j;
			}
			else{
				cnt = 1;
				while(lower){
					x = lower%10;
					lower /= 10;
					
					for(j=x-1; j>=0 && broken[j]; j--);
					if(j >= 0){
						lower = lower*10 + j;
						break;
					}
					
					cnt++;
				}
				if(lower == 0){
					cnt--;
					l_n--;
				}
				while(cnt--) lower = lower*10 + max_num;
			}
			
			flag = true;
			continue;
		}
		
		upper = upper*10 + num[i];
		lower = lower*10 + num[i];
	}
	
	ans = min(ans, u_n+upper-n_);
	if(lower || !broken[0]) ans = min(ans, l_n+n_-lower);
	
	cout << ans;
	
	return 0;
}
