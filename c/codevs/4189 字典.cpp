#include<stdio.h>
#include<string.h>
int tire[200001 * 8][26];
int cnt = 0;

void init(char s[])
{
	int len = strlen(s);
	int tmp = 0,now = 0;
	for(int i = 0 ;i < len;i++)
	{
		tmp = s[i] - 'a';
		if(tire[now][tmp] == 0) tire[now][tmp] = ++cnt;
		now = tire[now][tmp];
	}
	return ;
}

bool find(char s[])
{
	int len = strlen(s);
	int tmp = 0,now = 0;
	for(int i = 0;i < len;i++)
	{
		tmp = s[i] - 'a';
		if(tire[now][tmp] == 0) return false;
		now = tire[now][tmp];
	}
	return true;
}

int main()
{
	int n,m;
	scanf("%d",&n);
	for(int i = 0;i < n;i++)
	{
		char s[10010];
		scanf("%s",s);
		init(s);
	}
	scanf("%d",&m);
	for(int i = 0;i < m;i++)
	{
		char s[10010];
		scanf("%s",s);
		if(find(s))
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}
	}
	return 0;
}