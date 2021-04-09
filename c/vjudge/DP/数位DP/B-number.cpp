#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<math.h>
using namespace std;
int f[20][13][3],dight[20],len;
int dfs(int dep,bool limit,int status,int mod)
{
	if(dep == 0) return status == 2 && mod == 0;
	if(!limit && f[dep][mod][status] != -1) return f[dep][mod][status];
	int bit = limit ? dight[dep] : 9;
	int ans = 0;
	for(int i = 0;i <= bit;i++)
	{
		int _status;
		if(status == 2 || status == 1 && i == 3) _status = 2;
		else if(i == 1) _status = 1;
		else _status = 0;
		ans += dfs(dep - 1,i == bit && limit,_status, (mod * 10 + i) % 13);
	}
	if(!limit) f[dep][mod][status] = ans;
	return ans;
}
int solve(int n)
{
	memset(dight,0,sizeof(dight));
	len = 1;
	while(n)
	{
		dight[len] = n % 10;
		n /= 10;
		len++;
	}
	len--;
	memset(f,-1,sizeof(f));
	int ans = dfs(len,1,0,0);
	return ans;
}
int main()
{
	int n;
	while(~scanf("%d",&n))
		printf("%d\n",solve(n));
	return 0;
}