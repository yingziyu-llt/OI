#include<stdio.h>
#include<algorithm>
#include<stdlib.h>
using namespace std;
struct node
{
	int x,y,val;
}a[1000000];
int map[1010][1010];
bool cmp(node a,node b)
{
	return a.val > b.val;
}
int main()
{
	int n,m,k,tot = -1,ans = 0;
	scanf("%d%d%d",&n,&m,&k);
	for(int i = 1; i <= n;i++)
	{
		for(int j = 1; j <= m;j++)
		{
			scanf("%d",&map[i][j]);
			if(map[i][j] != 0)
			{
				a[++tot].val = map[i][j];
				a[tot].x = i;
			a[tot].y = j;
			}
			
		}
	}
	sort(a,a + tot + 1,cmp);
	int nowx = 0,nowy = 0;
	k--;
	if(a[0].x * 2 > k)
	{
		printf("0");
		return 0;
	}
	k -= a[0].x;
	
	ans += a[0].val;
	nowy = a[0].x;
	nowx = a[0].y;
	for(int  i = 1; i <= tot; i++)
	{
		if(abs(nowx - a[i].y) + abs(nowy - a[i].x) + a[i].x + 1> k)
			break;
		else
		{
			ans += a[i].val;
			k -= abs(nowx - a[i].y) + abs(nowy - a[i].x);
			nowx = a[i].y;
			nowy = a[i].x;
			k--;
		}
	}
	printf("%d",ans);
	return 0;
}