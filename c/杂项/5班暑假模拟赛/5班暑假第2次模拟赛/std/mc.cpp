#include<stdio.h>
struct cmp
{
	int x,y,val;
}a[90010];
int c1[310][310],c2[310][310];
int f1,f2,m,n,k1,k2;
int dx[10]={0,1,-1,0,0};
int dy[10]={0,0,0,1,-1};

int main()
{
	freopen("mc.in","r",stdin);
	freopen("mc.out","w",stdout);
	int a1,sum;
	sum = 0;
	scanf("%d%d",&n,&a1);
	for(int i = 2 ; i <= n ; i++)
	{
		scanf("%d",&a1);
		if(a1 == 0) sum = sum + 1;
		if(a1 == 1) sum = sum + 2;
	}
	scanf("%d%d",&n,&m);
	for(int i = 1 ; i <= n ; i++)
		for(int j = 1 ; j <= m ; j++)
		{
			scanf("%d",&c1[i][j]);
			c2[i][j] = c1[i][j];
		}
	int st,ed;
	st = ed = 1;
	a[1].x = a[1].y = a[1].val = 1;
	while(st <= ed)
	{
		c1[a[st].x][a[st].y] = 1;
		for(int i = 1 ; i <= 4 ; i++)
		{
			int sx = a[st].x + dx[i],sy = a[st].y + dy[i];
			if(sx >= 1 && sx <= n && sy >= 1 && sy <= m)
			{
				if(c1[sx][sy] == 0)
				{
					a[++ed].val = a[st].val + 1;
					a[ed].x = sx;
					a[ed].y = sy;
					c1[sx][sy] = 1;
				}
				else if(c1[sx][sy] == 2)
				{
					k1 = a[st].val;
					f1 = true;
					break;
				}
			}
		}
		if(f1) break;
		st++;
	}
	st = ed = 1;
	a[1].x = a[1].y = a[1].val = 1;
	c2[1][1] = 1;
	while(st <= ed)
	{
		c2[a[st].x][a[st].y] = 0;
		for(int i = 1 ; i <= 4 ; i++)
		{
			int sx = a[st].x + dx[i],sy = a[st].y + dy[i];
			if(sx >= 1 && sx <= n && sy >= 1 && sy <= m)
			{
				if(c2[sx][sy] == 1)
				{
					a[++ed].val = a[st].val + 1;
					a[ed].x = sx;
					a[ed].y = sy;
					c2[sx][sy] = 0;
				}
				else if(c2[sx][sy] == 2)
				{
					k2 = a[st].val;
					f2 = true;
					break;
				}
			}
		}
		if(f2) break;
		st++;
	}
	if((sum/2)%2==1)
	{
		if(sum % 2 == 0) k1 = k1 + 2;
		else k1 = k1 + 1;
	}
	else 
	{
		if(sum % 2 == 0) k2 = k2+ 2;
		else k2 = k2 + 1;
	}
	if(f1 == false) k1 = 0x7fffffff;
	if(f2 == false) k2 = 0x7fffffff;
	k1 = k1 < k2 ? k1 : k2;
	printf("%d",k1 + sum);
}
