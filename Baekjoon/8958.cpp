#include <iostream>
#include <string>

using namespace std;

int main()
{
	int t, i, p, sum;
	string str;
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> t;
	while(t--){
		cin >> str;
		
		p = sum = 0;
		for(i=0; i<str.size(); i++){
			if(str[i] == 'O'){
				p++;
				sum += p;
			}
			else{
				p = 0;
			}
		}
		
		cout << sum << '\n';
	}
	
	return 0;
}
