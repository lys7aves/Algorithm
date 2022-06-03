#include <bits/stdc++.h>

using namespace std;

bool flag;
int sudoku[10][10];

void dfs(int x, int y)
{
	int i, j, z;
	
	if(flag) return;
	
	//if(x == 2) return;
	
	if(y == 9){
		dfs(x+1, 0);
		return;
	}
	
	if(x == 9){
		flag = true;
		
		for(i=0; i<9; i++){
			for(j=0; j<9; j++){
				cout << sudoku[i][j] << ' ';
			}
			cout << '\n';
		}
		
		return;
	}
	
	if(sudoku[x][y]){
		dfs(x, y+1);
		return;
	}
	
	for(z=1; z<=9; z++){
		for(i=0; i<9; i++){
			if(sudoku[x][i] == z) break;
			if(sudoku[i][y] == z) break;
		}
		if(i<9) continue;
		
		for(i=0; i<3; i++){
			for(j=0; j<3; j++){
				if(sudoku[x/3*3+i][y/3*3+j] == z) break;
			}
			if(j<3) break;
		}
		if(i<3) continue;
		
		sudoku[x][y] = z;
		dfs(x, y+1);
		sudoku[x][y] = 0;
	}
}

int main()
{
	int i, j;
	
	for(i=0; i<9; i++){
		for(j=0; j<9; j++){
			cin >> sudoku[i][j];
		}
	}
	
	dfs(0, 0);
	
	return 0;
}
