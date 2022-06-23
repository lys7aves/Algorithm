#include <bits/stdc++.h>

using namespace std;

deque<int> deq;
char p[100010];

int main()
{
	int t, n, i, x, l;
	char c;
	bool flag;
	
	scanf("%d", &t);
	while(t--){
		scanf(" %s", p);
		scanf("%d", &n);
		scanf(" %c", &c);
		for(i=0; i<n; i++){
			scanf("%d%c", &x, &c);
			deq.push_back(x);
		}
		if(n == 0) scanf("%c", &c);
		
		l = strlen(p);
		flag = true;
		for(i=0; i<l; i++){
			if(p[i] == 'R'){
				flag = !flag;
			}
			if(p[i] == 'D'){
				if(deq.empty()) break;
				if(flag) deq.pop_front();
				else deq.pop_back();
			}
		}
		
		if(i < l){
			printf("error\n");
			continue;
		}
		
		printf("[");
		while(!deq.empty()){
			if(flag){
				printf("%d", deq.front());
				deq.pop_front();
			}
			else{
				printf("%d", deq.back());
				deq.pop_back();
			}
			if(!deq.empty()) printf(",");
		}
		printf("]\n");
	}
	
	return 0;
}
