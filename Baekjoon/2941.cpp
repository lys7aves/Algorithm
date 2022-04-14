#include <bits/stdc++.h>

using namespace std;

int main()
{
	int cnt=0, l, i;
	char str[110];
	
	cin >> str;
	
	l = strlen(str);
	for(i=0; i<l; i++){
		if(strncmp(str+i, "c=", 2) == 0) i++;
		if(strncmp(str+i, "c-", 2) == 0) i++;
		if(strncmp(str+i, "dz=", 3) == 0) i+=2;
		if(strncmp(str+i, "d-", 2) == 0) i++;
		if(strncmp(str+i, "lj", 2) == 0) i++;
		if(strncmp(str+i, "nj", 2) == 0) i++;
		if(strncmp(str+i, "s=", 2) == 0) i++;
		if(strncmp(str+i, "z=", 2) == 0) i++;
		cnt++;
	}
	
	cout << cnt;
	
	return 0;
}
