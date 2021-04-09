#include<stdio.h>
#include<string.h>
char s[10010];
int main()
{
	int cnt = 0;
	while(~ scanf("%s",s))//scanf("") != EOF
	{
		cnt += strlen(s);
		memset(s,0,sizeof(s));
	}
	printf("%d",cnt);
	return 0;
} 