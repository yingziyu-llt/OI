#include<cstdio>
#include<string.h>
int st,ed,m,n,flag;
char ch[6][11],zx[6][11],zc[6][11],zv[6][11],zb[6][11];
int dx[5],dy[5];
struct{
	int x,y,val;
}a[500];
int qw(int &m,int &n)
{
	int i,j;
	if(m==3)
	{
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				if(zx[i][j]=='.') ch[i][j]=='.';
				if(zx[i][j]=='@') ch[i][j]=='@';
			}
		}
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				if(zc[i][j]=='.') ch[i][j]=='.';
				if(zc[i][j]=='@') ch[i][j]=='@';
			}
		}
	}
	if(m==4)
	{
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				if(zx[i][j]=='.') ch[i][j]=='.';
				if(zx[i][j]=='@') ch[i][j]=='@';
			}
		}
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				if(zc[i][j]=='.') ch[i][j]=='.';
				if(zc[i][j]=='@') ch[i][j]=='@';
			}
		}
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				if(zv[i][j]=='.') ch[i][j]=='.';
				if(zv[i][j]=='@') ch[i][j]=='@';
			}
		}
	}
	if(m==5)
	{
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				if(zx[i][j]=='.') ch[i][j]=='.';
				if(zx[i][j]=='@') ch[i][j]=='@';
			}
		}
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				if(zc[i][j]=='.') ch[i][j]=='.';
				if(zc[i][j]=='@') ch[i][j]=='@';
			}
		}
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				if(zv[i][j]=='.') ch[i][j]=='.';
				if(zv[i][j]=='@') ch[i][j]=='@';
			}
		}
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				if(zb[i][j]=='.') ch[i][j]=='.';
				if(zb[i][j]=='@') ch[i][j]=='@';
			}
		}
	}
	return 0;
}
int sc(int &m,int &n)
{
	int i,j;
	if(m==3)
	{
		for(i=1;i<=n;i++) scanf("%s",ch[i]+1);	
		for(i=1;i<=n;i++) scanf("%s",zx[i]+1);
		for(i=1;i<=n;i++) scanf("%s",zc[i]+1);
		qw(m,n);
	}
	if(m==4)
	{
		for(i=1;i<=n;i++) scanf("%s",ch[i]+1);	
		for(i=1;i<=n;i++) scanf("%s",zx[i]+1);
		for(i=1;i<=n;i++) scanf("%s",zc[i]+1);
		for(i=1;i<=n;i++) scanf("%s",zv[i]+1);
		qw(m,n);
	}
	if(m==5)
	{
		for(i=1;i<=n;i++) scanf("%s",ch[i]+1);	
		for(i=1;i<=n;i++) scanf("%s",zx[i]+1);
		for(i=1;i<=n;i++) scanf("%s",zc[i]+1);
		for(i=1;i<=n;i++) scanf("%s",zv[i]+1);
		for(i=1;i<=n;i++) scanf("%s",zv[i]+1);
		for(i=1;i<=n;i++) scanf("%s",zb[i]+1);
		qw(m,n);
	}
	return 0;
}
int main()
{
	int i,j;
	dx[1]=1;dx[2]=-1;
	dy[3]=1;dy[4]=-1;
	freopen("find.in","r",stdin);
	freopen("find.out","w",stdout);
	while(1)
	{
		flag=0;
		memset(ch,0,sizeof(ch));
		scanf("%d%d",&m,&n);
		if(m==1)
		{
		 scanf("%s",ch[1]+1);
		}
		if(m==2)
		{
			for(i=1;i<=n;i++) scanf("%s",ch[i]+1);	
		}
		if(m>2) sc(m,n);
		if(m==0) return 0;
		a[1].x=1;a[1].y=1;a[1].val=1;
		st=1;ed=1;
		while(st<=ed)
		{
			ch[a[st].x][a[st].y]='#';
			for(i=1;i<=4;i++)
			{
				int sx=a[st].x+dx[i],sy=a[st].y+dy[i];
				if(sx>=1 && sx<=n && sy>=1 && sy<=n)
				{
					if(ch[sx][sy]=='.')
					{
						a[++ed].val=a[st].val+1;
						a[ed].x=sx;
						a[ed].y=sy;
						ch[sx][sy]='#';
					}
					else if(ch[sx][sy]=='@')
					{
						printf("YES\n");
						flag=1;
						break;
					}
				}
			}
			if(flag==1) break;
			st++;
		}
		if(flag==0) printf("NO\n");
	}
	return 0;
}
