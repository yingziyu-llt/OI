#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;
struct ss
{
	int val,num,kind;
}goods[10010];
int num[10010];
bool cmp(ss a,ss b)
{
	return a.val > b.val;
}
int main()
{
	freopen("Diet.in","r",stdin);
	freopen("Diet.out","w",stdout);
	int n,m,k;
	scanf("%d%d%d",&n,&m,&k);
	for(int i = 1;i <= k;i++)
		scanf("%d",&num[i]);
	for(int i = 1;i <= n;i++)
	{
		int c = 0;
		scanf("%d %d",&goods[i].val,&c);
		goods[i].num = 1;
		goods[i].kind = c;
	}
	sort(goods + 1,goods + n + 1,cmp);
	int ans = 0;
	for(int i = 1;i <= n;i++)
	{
		if(m > goods[i].num && num[goods[i].kind] - goods[i].num >= 0)
		{
			m -= goods[i].num;
			ans += goods[i].num * goods[i].val;
			num[goods[i].kind] -= goods[i].num;
		}
		else if(m <= goods[i].num && num[goods[i].kind] - goods[i].num >= 0)
		{
			ans += m * goods[i].val;
			break;
		}
		else
		{
			ans += num[goods[i].kind] * goods[i].val;
			m -= num[goods[i].kind];
			num[goods[i].kind] = 0;
		}
	}
	printf("%d",ans);
	return 0;
}