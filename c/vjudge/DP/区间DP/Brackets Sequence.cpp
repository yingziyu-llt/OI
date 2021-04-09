#include<stdio.h>
#include<algorithm>
#include<string.h>
int f[1000][1000];
char s[1000];
int p[1000][1000];
void print(int i,int j)
{
	if(i > j) return ; 
	if(i == j)
	{
		if(s[i] == '(' || s[i] == ')') printf("()");
		else printf("[]");
	}
	else if(p[i][j] == -1)
	{
		putchar(s[i]);
		print(i + 1,j - 1);
		putchar(s[j]);
	}
	else
	{
		print(i,p[i][j]);
		print(p[i][j] + 1,j);
	}
	return ;
}
int main()
{
	while(gets(s + 1))
	{
		int n = strlen(s + 1);
		if(!n)
		{ 
			puts("");
			continue;
		}
		memset(f,0x3f,sizeof(f));
		for(int i = 1;i <= n;i++)
			f[i][i] = 1,f[i][i - 1] = 0;
		for(int l = 2;l <= n;l++)
		{
			for(int i = 1;i + l - 1 <= n;i++)
			{
				int j = i + l - 1;
				if(s[i] == '(' && s[j] == ')' || s[i] == '[' && s[j] == ']')
				{
					f[i][j] = f[i + 1][j - 1];
					p[i][j] = -1;
				}
				for(int k = i;k < j;k++)
				{
					if(f[i][j] > f[i][k] + f[k + 1][j])
					{
						f[i][j] = f[i][k] + f[k + 1][j];
						p[i][j] = k;
					}
				}
			}
		}
		print(1,n);
		printf("\n");
	}
	return 0;
}