#include<stdio.h>
#include<algorithm>
using namespace std;
int line[1001];
int maxn = 0,minn = 0x7fffffff,m,n;
const int n9[9]={9,81,729,6561,59409,531441,4782969,43046721,387420489};
int mod(int n){return ((n % 10) + 10) % 10;}
void dfs(int dep,int from,int val,int cnt)
{
	int sum = 0;
	if(dep == m)
	{
		for(int i = from;i <= n + cnt;i++)
			sum += line[i];
		maxn = max(maxn,val * mod(sum));
		minn = min(minn,val * mod(sum));
		return ;
	}
	if (val >= minn && val * n9[m - dep] <= maxn)
		return;
	for(int i = 0;i + from <= n + cnt - m + 1;i++)
	{
		sum = 0;
		for(int j = from;j <= i + from;j++)
			sum += line[j];
		dfs(dep + 1,from + i + 1,val * mod(sum),cnt);
	}
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i = 1;i <= n;i++)
		scanf("%d",&line[i]);
	for(int i = n + 1;i <= 2 * n;i++)
		line[i] = line[i - n];
	for(int i = 1;i <= n;i++)
		dfs(1,i,1,i - 1);
	printf("%d\n%d",minn,maxn);
	return 0;
}