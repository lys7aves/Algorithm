#include <stdio.h>

#define MAXN 300001

int m=1, cnt;
int A[MAXN], B[MAXN];
int tree[8*MAXN], s[4*MAXN], e[4*MAXN];

void setting(int i);
int changeOne(int idx, int diff);
void update(int i);
bool change(int i, int idx, int flag);

void printTree(int *t);

int main()
{
	int n, q, d, diff, flag;
	int i;
	char x;
	
	scanf("%d %d", &n, &q);
	n++;
	
	for(i=1; i<n; i++) scanf("%1d", &A[i]);
	for(i=1; i<n; i++) scanf("%1d", &B[i]);
	
	while(m < n) m *= 2;
	for(i=n-1; i>=0; i--){
		tree[m+i] += A[i] + B[i];
		tree[m+i-1] = tree[m+i]/10;
		tree[m+i] %= 10;
	}
	for(i=n; i<m; i++) tree[m+i] = -1;
	
	for(i=0; i<m; i++) s[m+i] = e[m+i] = i;
	setting(1);
	
//	printTree(tree);
//	printTree(s);
//	printTree(e);
	
	while(q--){
//		printf("---------------------------\n");
		scanf(" %c %d %d", &x, &i, &d);
		if(x == 'A'){
			diff = d-A[n-i];
			A[n-i] = d;
		}
		else{
			diff = d-B[n-i];
			B[n-i] = d;
		}
		
		if(diff == 0){
			printf("0\n");
			continue;
		}
		
		flag = changeOne(n-i, diff);
//		printf("diff, flag: %d %d\n", diff, flag);
//		printf("changeOne result:\n");
//		printTree(tree);
		if(flag == 0){
			printf("1\n");
			continue;
		}
		
		cnt = 1;
		change(1, n-i-1, flag);
		printf("%d\n", cnt);
//		printf("last result:\n");
//		printTree(tree);
	}
	
	return 0;
}

void setting(int i)
{
	if(i >= m) return;
	
	setting(i*2);
	setting(i*2+1);
	
	s[i] = s[i*2];
	e[i] = e[i*2+1];
	if(tree[i*2] == tree[i*2+1]) tree[i] = tree[i*2];
	else tree[i] = -1;
}

int changeOne(int idx, int diff)
{
	int i=1, flag=0;
	
	while(i < m){
		if(tree[i] != -1){
			tree[i*2] = tree[i];
			tree[i*2+1] = tree[i];
		}
		
		if(idx <= e[i*2]) i = i*2;
		else i = i*2+1;
	}
	
//	printTree(tree);
//	printf("%d %d %d %d\n", idx, i, diff, tree[i]);
	tree[i] += diff;
	if(tree[i] >= 10){
		flag = 1;
		tree[i] -= 10;
	}
	else if(tree[i] < 0){
		flag = -1;
		tree[i] += 10;
	}
	
	update(i);
	
	return flag;
}

void update(int i)
{
	i /= 2;
	while(i){
		if(tree[i*2] == tree[i*2+1]) tree[i] = tree[i*2];
		else tree[i] = -1;
		
		i /= 2;
	}
}

bool change(int i, int idx, int flag)
{
//	printf("%d %d %d\n", i, idx, flag);
	if(tree[i] != -1){
		tree[i*2] = tree[i];
		tree[i*2+1] = tree[i];
	}

	if(e[i] <= idx){
		if(flag == 1 && tree[i] == 9){
			tree[i] = 0;
			update(i);
			cnt += e[i]-s[i]+1;
			return true;
		}
		if(flag == -1 && tree[i] == 0){
			tree[i] = 9;
			update(i);
			cnt += e[i]-s[i]+1;
			return true;
		}
		
		if(i >= m){
			tree[i] += flag;
			update(i);
			cnt++;
			return false;
		}
		if(change(i*2+1, idx, flag)){
			return change(i*2, idx, flag);
		}
		return false;
	}
	else{
		if(idx > e[i*2]){
			if(change(i*2+1, idx, flag)){
				return change(i*2, idx, flag);
			}
			return false;
		}
		else{
			return change(i*2, idx, flag);
		}
	}
}

void printTree(int *t)
{
	int i, j=2;
	for(i=1; i<2*m; i++){
		if(i == j){
			printf("\n");
			j *= 2;
		}
		printf("%d ", t[i]);
	}
	printf("\n");
}
