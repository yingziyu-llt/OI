#include<stdio.h>
#include<algorithm>
#include<string.h>
const int MaxLen = 31000;
char s1[MaxLen],s2[MaxLen];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%s%s",s1,s2);
		int len1 = strlen(s1),len2 = strlen(s2);
		for(int i = 0;i < len1;i++)
		{
			if((s1[i - 1] == '0' && s1[i] == '*') || (s1[i - 1] == s1[i] && s1[i - 1] == '*'))
			{
				s1[i] = '0';
			}
		}
		int j = 0;
		char c;
		bool flag = false;
		for(int i = 0;i < len2;i++)
		{
			int xlen = 1;
			if(s1[j] != '*')
				c = s1[j];
			if(s2[i] != c)
			{
				flag = true;
				printf("No\n");
				break;
			}
			while(s2[i] == s2[i + 1] && s1[j] == '*' && s2[i] == c)
			{
				xlen++;
				i++;
			}
			while(s1[j] == '0')
				j++;
			while(s1[j] == c)
			{
				xlen--;
				j++;
				if(xlen < 0)
				{
					flag = true;
					break;
				}
			}
			if(flag)
			{
				printf("No\n");
				break;
			}
			while(s1[j] == 0)
				j++;
		}
		if(!flag)
			printf("Yes\n");
	}
	return 0;
}