#include<stdio.h>
int bit_tree[1100000],n;
int lowbit(int x)
{
	return x & (-x);
}
int query(int x)
{
	if(x == 0) return 0;
	long long res = 0;
	for(int i = x;i >= 1;i -= lowbit(i))
		res += bit_tree[i];
	return res;
}
void change(int x,int add)
{
	for(int i = x;i <= n;i += lowbit(i))
		bit_tree[i] += add;
}
int main()
{
	freopen("hoodle.in","r",stdin);
	freopen("hoodle.out","w",stdout);
	int q;
	scanf("%d%d",&n,&q);
	for(int i = 1;i <= n;i++)
	{
		int k;
		scanf("%d",&k);
		change(i,k);
	}
	for(int i = 1;i <= q;i++)
	{
		int request;
		scanf("%d",&request);
		if(request == 1)
		{
			int x,y;
			scanf("%d%d",&x,&y);
			printf("%d\n",query(y) - query(x - 1));
		}
		else if(request == 2)
		{
			int x;
			scanf("%d",&x);
			int l = 0,r = n + 1;
			while(l < r)
			{
				int mid = (l + r) >> 1;
				if(query(mid) > x) r = mid;
				else l = mid + 1;
			}
			printf("%d\n",l - 1);
		}
		else
		{
			int x,y;
			scanf("%d%d",&x,&y);
			change(x,y);
		}
	}
	return 0;
}