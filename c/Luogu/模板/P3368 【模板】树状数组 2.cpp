#include<stdio.h>
using namespace std;
int tree[500010],a[500010],n;
int lowbit(int x) { return x & (-x);}
void change(int x,int d)
{
	for(int i = x;i >= 1;i -= lowbit(i))
		tree[i] += d;
}
int query(int x)
{
	if(x == 0) return 0;
	int res = 0;
	for(int i = x;i <= n;i += lowbit(i))
		res += tree[i];
	return res;
}
int main()
{
	int m;
	scanf("%d%d",&n,&m);
	for(int i = 1;i <= n;i++)
		scanf("%d",&a[i]);
	for(int i = 0;i < m;i++)
	{
		int commond,x,y,k;
		scanf("%d",&commond);
		if(commond == 1)
		{
			scanf("%d%d%d",&x,&y,&k);
			change(y,k);
			change(x - 1,-k);
		}
		else
		{
			scanf("%d",&x);
			printf("%d\n",query(x) + a[x]);
		}
	}
	return 0;
}