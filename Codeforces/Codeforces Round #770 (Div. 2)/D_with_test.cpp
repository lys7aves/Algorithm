#include <stdio.h>
#include <algorithm>
#include <time.h>
#include <stdlib.h>

#define TEST false
#define PRINT_PROCESS false
#define MAXN 1000

using namespace std;

int d_01[MAXN], d_0x[MAXN], d_1xy;

int _input=-1, _n, _cnt=0;
int _a[MAXN+1];

int input();
void guess(int i, int j, int k);
void answer(int i, int j);

int main()
{
	srand(time(NULL));
	
	int t, n, i, x, y, maxi, a, b;
	
	scanf("%d", &t);
	while(t--){
		n = input();
		
		for(i=2; i<n; i++){
			guess(0, 1, i);
			d_01[i] = input();
		}
		
		x = 2;
		for(i=2; i<n; i++){
			if(d_01[i] > d_01[x]) x = i;
		}
		
		d_0x[1] = d_01[x];
		for(i=2; i<n; i++){
			if(x == i) continue;
			
			guess(0, x, i);
			d_0x[i] = input();
		}
		
		y = 1;
		d_0x[y] = -1;
		for(i=2; i<n; i++){
			if(i == x) continue;
			if(d_0x[i] > d_0x[y]) y = i;
		}
		
		guess(1, x, y);
		d_1xy = input();
		
		maxi = max(d_01[x], max(d_01[y], max(d_0x[y], d_1xy)));
		
		if(d_01[x] == maxi && d_01[y] == maxi) answer(0, 1);
		else if(d_01[x] == maxi && d_0x[y] == maxi) answer(0, x);
		else if(d_01[y] == maxi && d_0x[y] == maxi) answer(0, y);
		else if(d_01[x] == maxi && d_1xy == maxi) answer(1, x);
		else if(d_01[y] == maxi && d_1xy == maxi) answer(1, y);
		else if(d_0x[y] == maxi && d_1xy == maxi) answer(x, y);
	}
	
	return 0;
}

int input()
{ 
#if !TEST
	int x;
	scanf("%d", &x);
	return x;
	
#else
	if(_input == -1){
		_n = rand()%(MAXN-3)+4;
		int MAXA = 1000000000;
		for(int i=1; i<=_n; i++) _a[i] = rand()%MAXA+1;
		_a[rand()%_n+1] = 0;
		
		if(PRINT_PROCESS){
			printf("%d\n", _n);
			for(int i=1; i<=_n; i++) printf("%d ", _a[i]);
			printf("\n");
		}
		
		_input = _n;
		return _n;
	}
	
	else{
		return _input;
	}

#endif
}

void guess(int i, int j, int k)
{
	i++; j++; k++;
	
#if !TEST
	printf("? %d %d %d\n", i, j, k);
	fflush(stdout);
	
#else
	if(i<1 || i>_n || j<1 || j>_n || k<1 || k>_n){
		printf("? %d %d %d\n", i, j, k);
		printf("-1\n");
		while(1);
	}
	_cnt++;
	_input = max(_a[i], max(_a[j], _a[k])) - min(_a[i], min(_a[j], _a[k]));
	if(PRINT_PROCESS){
		printf("? %d %d %d\n", i, j, k);
		printf("%d\n", _input);
	}

#endif
}

void answer(int i, int j)
{
	i++; j++;
	
#if !TEST
	printf("! %d %d\n", i, j);
	fflush(stdout);
	
#else
	if(i<1 || i>_n || j<1 || j>_n){
		printf("! %d %d\n", i, j);
		printf("-1\n");
		while(1);
	}
	
	if(PRINT_PROCESS) printf("!%d %d\n", i, j);
	
	printf("%d / %d\n", _cnt, 2*_n-2);
	if(_a[i]*_a[j] == 0) printf("Correct!\n\n");
	else{
		printf("Wrong :(\n\n");
		
		printf("%d\n", _n);
		for(int i=1; i<=_n; i++) printf("%d ", _a[i]);
		printf("\n");
		while(1);
	}
	
	_input = -1;
	_cnt = 0;

#endif
}
