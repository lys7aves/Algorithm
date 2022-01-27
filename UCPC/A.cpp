#include <stdio.h>

char str[3000];

int checking(int s, char *num)
{
	if(*num == '\0') return s-1;
	
	if(s < 10){
		if(num[0]-'0' != s) return -1;
		return checking(s+1, num+1);
	}
	else if(s < 100){
		if((num[0]-'0') != s/10 || (num[1]-'0') != s%10) return -1;
		return checking(s+1, num+2);
	}
	else{
		if((num[0]-'0') != s/100 || (num[1]-'0') != (s/10)%10 || (num[2]-'0') != s%10) return -1;
		return checking(s+1, num+3);
	}
}

int main()
{
	int s, e;
	
	scanf("%s", str);
	
	s = str[0] - '0';
	e = checking(s, str);
	if(e > 0){
		printf("%d %d", s, e);
		return 0;
	}
	
	s = (str[0]-'0')*10 + (str[1]-'0');
	e = checking(s, str);
	if(e > 0){
		printf("%d %d", s, e);
		return 0;
	}
	
	s = (str[0]-'0')*100 + (str[1]-'0')*10 + (str[2]-'0');
	e = checking(s, str);
	if(e > 0){
		printf("%d %d", s, e);
		return 0;
	}
	
	return 0;
}
