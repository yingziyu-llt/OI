#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;
long long dight[20],len,tenPows[20];
const long long MOD = 1e9+7;
struct Node
{
	long long cnt,sum,ssum;
	void mod()
	{
		cnt %= MOD;
		sum %= MOD;
		ssum %= MOD;
	}
}f[20][7][7];
Node dfs(int dep,int pre1,int pre2,bool limit)
{
	if(dep == 0) return (Node){(pre1 != 0 && pre2 != 0),0,0};
	if(!limit && f[dep][pre1][pre2].cnt != -1) return f[dep][pre1][pre2];
	int bit = limit ? dight[dep] : 9;
	Node tmp,ans;
	ans = (Node){0,0,0};
	for(int i = 0;i <= bit;i++)
	{
		if(i == 7) continue;
		tmp = dfs(dep - 1,(pre1 + i) % 7,(pre2 * 10 + i) % 7,limit && i == bit);
		tmp.mod();
		ans.cnt += tmp.cnt;
		ans.sum += (i % MOD * tenPows[dep - 1] % MOD * tmp.cnt % MOD + tmp.sum % MOD) % MOD;
		ans.ssum += (tmp.cnt * (i * tenPows[dep - 1]) % MOD * (i * tenPows[dep - 1]) % MOD + 2 * (i * tenPows[dep - 1]) % MOD * tmp.sum + tmp.ssum % MOD) % MOD;
		ans.mod();
	}
	if(!limit) f[dep][pre1][pre2] = ans;
	return ans;
}

long long solve(long long n)
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
	long long ans = dfs(len,0,0,1).ssum;
	return ans;
}

int main()
{
	int T;
	scanf("%d",&T);
	tenPows[0] = 1;
	for(int i = 1;i <= 19;i++)
		tenPows[i] = tenPows[i - 1] * 10 % MOD;
	for(int i = 0;i < 20;i++)
		for(int j = 0;j < 7;j++)
			for(int k = 0;k < 7;k++)
				f[i][j][k].cnt = -1;
	while(T--)
	{
		long long l,r;
		scanf("%lld%lld",&l,&r);
		printf("%lld\n",(solve(r) - solve(l - 1) % MOD + MOD) % MOD);
	}
	return 0;
}