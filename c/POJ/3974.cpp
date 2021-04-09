#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;
char s[1100000];
unsigned long long hash1[1100000],hash2[1100000];
unsigned long long p[1100000];
int main()
{
	int casenum;
	p[0] = 1;
	for(int i = 1;i < 1100000;i++)
		p[i] = p[i - 1] * 131;
	scanf("%d",&casenum);
	for(int _i = 0;_i < casenum;_i++)
	{
		memset(s,0,sizeof(s));
		scanf("%s",s + 1);
		s[0] = '0';
		int len = strlen(s);
		hash1[0] = 1;
		for(int i = 1;i < len;i++)
			hash1[i] = hash1[i - 1] * 131 + s[i] - 'a' + 1;
		hash2[i + 1] = 0;
		for(int i = n;i > 0;i--)
			hash2[i] = hash2[i + 1] * 131 + s[i] - 'a' + 1;
		int 
	}
}