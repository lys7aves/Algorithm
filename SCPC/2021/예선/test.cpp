#include <stdio.h>
#include <algorithm>

using namespace std;

struct w4{
	int w[4];
};

bool comp(const int x[4], const int y[4]){
	return x[3] > y[3];
}

int w[100][4];

int main()
{
	int n, i;
	
	scanf("%d", &n);
	for(int i=0; i<n; i++){
		for(int j=0; j<4; j++){
			scanf("%d", &w[i][j]);
		}
	}
	
	sort(w, w+n, comp);
	
	for(int i=0; i<n; i++){
		for(int j=0; j<4; j++){
			printf("%d ", w[i][j]);
		}
		printf("\n");
	}
	
	return 0;
}
