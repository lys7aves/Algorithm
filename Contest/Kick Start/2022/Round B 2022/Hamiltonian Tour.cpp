#include <bits/stdc++.h>

#define MAXR 210
#define MAXC 210

using namespace std;

int r, c;
bool b[MAXR][MAXC];
vector<char> ans;

int dx[4]={-1,0,1,0};
int dy[4]={0,1,0,-1};
char dir[4]={'N', 'E', 'S', 'W'};

void dfs(int x, int y, int z);
void move(int d1, int d2);

int main()
{
	int T, C, i, j;
	string str;
	bool flag;
	
	cin >> T;
	for(C=1; C<=T; C++){
		cin >> r >> c;
		for(i=1; i<=r; i++){
			cin >> str;
			for(j=1; j<=c; j++){
				if(str[j-1] == '*') b[i][j] = false;
				else b[i][j] = true;
			}
		}
		
		for(i=1; i<=r; i++) b[i][0] = b[i][c+1] = true;
		for(j=1; j<=c; j++) b[0][j] = b[r+1][j] = true;
		
		ans.clear();
		dfs(1, 1, 1);
		
		cout << "Case #" << C << ": ";
		
		flag = true;
		for(i=1; i<=r; i++){
			for(j=1; j<=c; j++){
				flag &= b[i][j];
			}
		}
		
		if(flag){
			for(i=0; i<ans.size()-1; i++) cout << dir[ans[i]];
			cout << 'N';
			cout << '\n';
		}
		else cout << "IMPOSSIBLE\n";
	}
	
	return 0;
}

void dfs(int x, int y, int z)
{
	int d, last_d=z;
	
	b[x][y] = true;
	
	for(int k=0; k<4; k++){
		d = (z+k-1+4)%4;
		
		if(b[x+dx[d]][y+dy[d]]) continue;
		move(last_d, d);
		dfs(x+dx[d], y+dy[d], d);
		
		last_d = (d+2)%4;
	}
	
	move(last_d, (z+2)%4);
}

void move(int d1, int d2)
{
	// turn left
	if((d1-1+4)%4 == d2){
		ans.push_back(d2);
	}
	// go straight
	if(d1 == d2){
		ans.push_back(d1);
		ans.push_back(d1);
	}
	// turn right
	if((d1+1)%4 == d2){
		ans.push_back(d1);
		ans.push_back(d2);
		ans.push_back(d2);
	}
	// go back
	if((d1+2)%4 == d2){
		ans.push_back(d1);
		ans.push_back((d1+1)%4);
		ans.push_back((d1+2)%4);
		ans.push_back((d1+2)%4);
	}
}
