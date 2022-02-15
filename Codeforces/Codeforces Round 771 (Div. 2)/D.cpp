#include <stdio.h>

#define MAXN 1010

int a[MAXN][MAXN];
int last_in_row[MAXN], last_in_col[MAXN];

int main()
{
	int n, m, i, j;
	int last_row=0, last_col=0, rlast=0, clast=0;
	int square;
	bool row=true, col=true;
	
	scanf("%d %d", &n, &m);
	for(i=1; i<=n; i++){
		for(j=1; j<=m; j++){
			scanf("%d", &a[i][j]);
		}
	}
	
	for(i=1; i<=n; i++){
		for(j=1; j<=m; j++){
			if(a[i][j] == a[i][j+1]) last_in_row[i] = j;
			if(a[i][j] == a[i+1][j]) last_in_col[j] = i;
		}
	}
	
	for(i=1; i<=n; i++) row &= (last_in_row[i] != 0);
	for(j=1; j<=m; j++) col &= (last_in_col[j] != 0);
	
	for(i=1; i<n; i++){
		square = 0;
		for(j=1; j<=m; j++){
			if(a[i][j] != a[i+1][j]) break;
			if((a[i][j] == a[i][j+1]) && (a[i][j] == a[i+1][j]) && (a[i][j] == a[i+1][j+1])) square = j;
		}
		
		if(j==m+1 && square){
			last_row = i;
			rlast = square;
		}
	}
	for(j=1; j<m; j++){
		square = 0;
		for(i=1; i<=n; i++){
			if(a[i][j] != a[i][j+1]) break;
			if((a[i][j] == a[i][j+1]) && (a[i][j] == a[i+1][j]) && (a[i][j] == a[i+1][j+1])) square = i;
		}
		
		if(i==n+1 && square){
			last_col = j;
			clast = square;
		}
	}
	
//	printf("%d %d %d %d %d %d\n", row, last_row, rlast, col, last_col, clast);
	
	if(row && last_row!=0){
		printf("%d\n", (n-1)*(m-1));
		
		for(i=1; i<last_row; i++){
			for(j=1; j<last_in_row[i]; j++) printf("%d %d %d\n", i, j, a[i][j]);
			for(j=m-1; j>last_in_row[i]; j--) printf("%d %d %d\n", i, j, a[i][j+1]);
			printf("%d %d %d\n", i, j, a[i][j]);
		}
		for(i=n-1; i>last_row; i--){
			for(j=1; j<last_in_row[i+1]; j++) printf("%d %d %d\n", i, j, a[i+1][j]);
			for(j=m-1; j>last_in_row[i+1]; j--) printf("%d %d %d\n", i, j, a[i+1][j+1]);
			printf("%d %d %d\n", i, j, a[i+1][j]);
		}
		
		for(j=1; j<rlast; j++) printf("%d %d %d\n", i, j, a[i][j]);
		for(j=m-1; j>rlast; j--) printf("%d %d %d\n", i, j, a[i][j+1]);
		printf("%d %d %d\n", i, j, a[i][j]);
		
		return 0;
	}
	if(col && last_col!=0){
		printf("%d\n", (n-1)*(m-1));
		
		for(j=1; j<last_col; j++){
			for(i=1; i<last_in_col[j]; i++) printf("%d %d %d\n", i, j, a[i][j]);
			for(i=n-1; i>last_in_col[j]; i--) printf("%d %d %d\n", i, j, a[i+1][j]);
			printf("%d %d %d\n", i, j, a[i][j]);
		}
		for(j=m-1; j>last_col; j--){
			for(i=1; i<last_in_col[j+1]; i++) printf("%d %d %d\n", i, j, a[i][j+1]);
			for(i=n-1; i>last_in_col[j+1]; i--) printf("%d %d %d\n", i, j, a[i+1][j+1]);
			printf("%d %d %d\n", i, j, a[i][j+1]);
		}
		
		for(i=1; i<clast; i++) printf("%d %d %d\n", i, j, a[i][j]);
		for(i=n-1; i>clast; i--) printf("%d %d %d\n", i, j, a[i+1][j]);
		printf("%d %d %d\n", i, j, a[i][j]);
		
		return 0;
	}
	
	printf("-1");
	
	return 0;
}
