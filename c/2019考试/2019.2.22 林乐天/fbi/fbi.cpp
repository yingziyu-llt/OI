#include<stdio.h>
int lowbit(int n)
{
	return n & (-n);
}
int bit_tree[10010];
int a[4096];
int n,m;
int tot;
int poww[] = {1,2,4,8,16,32,64,128,256,512,1024,2048};
//BIT Tree
long long query(int x)
{
	if(x == 0) return 0;
	long long res = 0;
	for(int i = x;i >= 1;i -= lowbit(i))
		res += bit_tree[i];
	return res;
}
void change(int x,int c)
{
	for(int i = x;i <= n;i += lowbit(i))
		bit_tree[i] += c;
}
//BIT tree
void dfs(int l,int r)
{
	if(l >= r)
	{
		if(a[l] == 0) printf("B");
		if(a[l] == 1) printf("I");
		tot--;
		return ;
	}
	dfs(l,(r - l) / 2 + l);
	if(tot <= 0) return ;
	dfs((r - l) / 2 + l + 1,r);
	if(tot <= 0) return ;
	int lt = query(l),rt = query(r);
	if(rt - lt + a[l] == l + r + 1)
		printf("I");
	else if(rt - lt + a[l] == 0)
		printf("B");
	else
		printf("F");
	tot--;
}
int main()
{
	scanf("%d%d",&n,&m);
	freopen("fbi.in","r",stdin);
	freopen("fbi.out","w",stdout);
	for(int i = 1;i <= poww[n];i++)
		scanf("%1d",&a[i]);
	for(int i = 1;i <= poww[n];i++)
		change(i,a[i]);
	for(int i = 0;i < m;i++)
	{
		int op,x,y;
		scanf("%d",&op);
		if(op == 1)
		{
			scanf("%d%d",&x,&y);
			change(x,y - a[x]);
			a[x] = y;
		}
		else
		{
			scanf("%d",&tot);
			dfs(1,tot);
			printf("\n");
		}
	}
	return 0;
}