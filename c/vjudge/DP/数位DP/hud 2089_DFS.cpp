#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;
int len;
int dight[9];
int make_dight(int n)
{
	len = 1;
	memset(dight,0,sizeof(dight));
	while(n)
	{
		dight[len] = n % 10;
		n /= 10;
		len++;
	}
	len--;
	return len;
}
long long f[9][10];
int dfs(int dep,bool limit,bool is6)
{
	if(!dep) return 1;
	if(!limit && f[dep][is6] != -1) return f[dep][is6];
	int bit = limit ? dight[dep] : 9;
	int ans = 0;
	for(int i = 0;i <= bit;i++)
	{
		if(i == 4 || i == 2 && is6) continue;
		ans += dfs(dep - 1,limit && i == bit,i == 6);
	}
	if(!limit) f[dep][is6] = ans;
	return ans;
}
int solve(int n)
{
	long long ans = 0;
	int len = make_dight(n);
	memset(f,-1,sizeof(f));
	return dfs(len,1,0);
}
int main()
{
	int m,n;
	while(1)
	{
		scanf("%d%d",&m,&n);
		if(m == 0 && n == 0) break;
		printf("%d\n",solve(n) - solve(m - 1));
	}
	return 0;
}