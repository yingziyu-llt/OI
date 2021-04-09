#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<math.h>
using namespace std;
long long f[200][13][3],dight[200],len;
char s[10010];
const long long MOD = 1000000007;
long long dfs(long long dep,bool limit,long long status,bool pre,long long last)
{
	if(!dep) return !pre;
	if(!limit && f[dep][last][status] != -1) return f[dep][last][status];
	long long bit = limit ? dight[dep] : 9;
	long long ans = 0;
	for(long long i = 0;i <= bit;i++)
	{
		if(status == 1 && i < last) continue;
		else if(pre != 0 && i == 0)	ans += dfs(dep - 1,limit && i == dight[dep],status,true,i) % MOD;
		else if(pre != 0)	ans += dfs(dep - 1,limit && i == dight[dep],status,false,i) % MOD;
		else if(i == last) ans += dfs(dep - 1,limit && i == dight[dep],status,false,i) % MOD;
		else ans += dfs(dep - 1,limit && i == dight[dep],i < last ? 2 : 1,false,i) % MOD;
		ans %= MOD;
	}
	if(!limit) f[dep][last][status] = ans;
	return ans;
}
long long solve()
{
	memset(dight,0,sizeof(dight));
	len = strlen(s);
	for(long long i = 0;i < len;i++)
		dight[i] = s[i] - '0';
	
	long long ans = dfs(len,1,0,1,-1);
	return ans;
}
int main()
{
	long long n;
	scanf("%lld",&n);
	memset(f,-1,sizeof(f));
	while(n-- && ~scanf("%s",s))
		printf("%lld\n",solve());
	return 0;
}