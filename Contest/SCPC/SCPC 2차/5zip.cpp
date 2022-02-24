#include <stdio.h>

int main()
{
	char x, y;
	
	freopen("output26.txt","r",stdin);
	freopen("new26.txt","w",stdout);
	
	while(scanf("%c%c", &x, &y) != EOF){
		printf("%c", (x-'A'+1)*7 + (y-'A'+1)+33);
		
		x = y = 'A'-1;
	}
	
	return 0;
}
