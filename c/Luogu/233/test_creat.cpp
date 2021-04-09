#include<stdio.h>
#include<stdlib.h>
#include<string.h> 
char c[100];
int to_string(int i)
{
	char s[100];
	memset(c,0,sizeof(c));
	int k = 0;
	while(i > 0)
	{
		s[k++] = i % 10 + '0';
		i /= 10;
	}
	int x = 0;
	while(k-- > 0)
	{
		c[k] = s[x++];
	}
	char ss[100] = "test";
	strcat(ss,c);
	strcpy(c,ss);
	strcat(c,".in");
	return 0;
}
int main()
{
	int i;
	for(int i = 0;i < 100;i++)
	{
		to_string(i);
		freopen(c,"w",stdout);
		printf("%d",i);
		fclose(stdout);
	}
	return 0;
}
