#include<algorithm>
#include<string.h>
#include<stdio.h>
using namespace std;
#define bigprime 233317
unsigned long long hashf(char s[])
{
	int i = 0,len = strlen(s);
	unsigned long long ans = 0;
	while(i < len)
	{
		ans = ans * bigprime + (s[i] - 'A' + 1);
		i++;
	}
	return ans;
}

int main()
{
	char str1[10000],str2[10000];
	char c = '\0';
	int i = 0;
	do
	{
		c = getchar();
		if(c == ' ')
			continue;
		if(c >= 'a' && c <= 'z')
			str1[i] = c - 'a' + 'A';
		if(c >= 'A' && c <= 'Z')
			str1[i] = c;
		i++;
	}while(c != '\n');
	i = 0;
	do
	{
		c = getchar();
		if(c == ' ')
			continue;
		if(c >= 'a' && c <= 'z')
			str2[i] = c - 'a' + 'A';
		if(c >= 'A' && c <= 'Z')
			str2[i] = c;
		i++;
	}while(c != '\n');
	i = 0;
	if(hashf(str1) == hashf(str2))
		printf("YES");
	else
		printf("NO");
	return 0;
}
