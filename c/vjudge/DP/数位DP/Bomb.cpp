#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;
int len;
int dight[30];
long long f[30][3];
long long dfs(int dep,bool limit,int status)
{
	if(!dep) return status == 2;
	if(!limit && f[dep][status] != -1) return f[dep][status];
	int bit = limit ? dight[dep] : 9;
	long long ans = 0;
	for(int i = 0;i <= bit;i++)
	{
		int _status;
		if(status == 2||status == 1 && i == 9) _status = 2;
		else if(i == 4) _status = 1;
		else _status = 0;
		ans += dfs(dep - 1,limit && i == bit,_status);
	}
	if(!limit) f[dep][status] = ans;
	return ans;
}
long long solve(long long n)
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
	memset(f,-1,sizeof(f));
	return dfs(len,1,0);
}
int main()
{
	long long m,n;
	scanf("%lld",&n);
	while(n--)
	{
		scanf("%lld",&m);
		printf("%lld\n",solve(m));
	}
	return 0;
}