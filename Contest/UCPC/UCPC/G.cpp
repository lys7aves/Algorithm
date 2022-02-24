#include <stdio.h>
#include <vector>

using namespace std;

bool chk[5000000];
vector<int> box[30];

int main()
{
	int k, n, i, j, x, y, l, p, cnt=0;
	
	scanf("%d %d", &k, &n);
	
	for(i=0; i<k; i++) box[i].push_back(1);
	
	for(i=1; cnt<k*n; i++){
		if(chk[i]) continue;
		
		x = -1;
		for(j=0; j<k; j++){
			if(box[j].size() > cnt/k+1) continue;
			y = box[j][box[j].size()-1];
			
			for(p=0; p<box[j].size(); p++){
				if(y-box[j][p]+i >= 5000000) continue;
				if(chk[y-box[j][p]+i]) break;
			}
			if(p < box[j].size()) continue;
			
			if(x < box[j][box[j].size()-1]){
				l = j;
				x = box[j][box[j].size()-1];
			}
		}
		
		if(x == -1) continue;
		
		for(j=0; j<box[l].size(); j++){
			if(x-box[l][j]+i >= 5000000) break;
			chk[x-box[l][j]+i] = true;
		}
		box[l].push_back(x+i);
		
		cnt++;
	}
	
	for(i=0; i<k; i++){
		for(j=0; j<n; j++){
			printf("%d ", box[i][j]);
		}
		printf("\n");
	}
	
	return 0;
}
