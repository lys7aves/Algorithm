#include <bits/stdc++.h>

using namespace std;

stack<char> s;

int main()
{
	int i=0;
	char c;
	bool flag=true;
	
	while(1){
		scanf("%c", &c);
		i++;
		
		if(c == '(' || c == '[') s.push(c);
		if(c == ')' || c == ']'){
			if(s.empty()){
				flag = false;
				continue;
			}
			if(c == ')' && s.top() == '[') flag = false;
			if(c == ']' && s.top() == '(') flag = false;
			
			s.pop();
		}
		if(c == '.'){
			if(i == 1) break;
			scanf("%c", &c);
			
			if(!s.empty()) flag = false;
			
			if(flag) cout << "yes\n";
			else cout << "no\n";
			
			i = 0;
			flag = true;
			while(!s.empty()) s.pop();
		}
	}
	
	return 0;
}
