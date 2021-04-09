#include<stdio.h>
#include<string.h>
#define H1 19491001
#define H2 19260817
bool vis1[H1 + 100],vis[H2 + 100];

long long hash1(char str[])
{
	long long res = 1;
	int len = strlen(str);
	for(int i = 0;i < len;i++)
		res = (res * 123 % H1  + str[i]) % H1;
	return res;
}

long long hash2(char str[])
{
	long long res = 1;
	int len = strlen(str);
	for(int i = 0;i < len;i++)
		res = (res * 123 % H2 + str[i]) % H2;
	return res;
}

int main()
{
	int n;
	int cnt = 0;
	char s[10010];
	scanf("%d",&n);
	for(int i = 0;i < n;i++)
	{
		memset(s,0,sizeof(s));
		scanf("%s",s);
		if(vis[hash1(s)] == false || vis[hash2(s)] == false)
		{
			cnt++;
			vis[hash1(s)] = true , vis[hash2(s)] = true;
		}
	}
	printf("%d",cnt);
	return 0;
}