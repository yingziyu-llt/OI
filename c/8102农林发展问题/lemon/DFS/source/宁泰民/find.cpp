#include <stdio.h> 
#include <string.h>
struct node
{
	int x,y,deep;
}a[22];
char map[11][11];
char tmp[11][11];
int st,ed,flag,m,n;
int dx[5]={1,-1,0,0}; 
int dy[5]={0,0,1,-1};
int main()
{
	freopen("find.in","r",stdin);
    freopen("find.out","w",stdout);
	while(scanf("%d %d",&m,&n)&&m&&n)
	{		
		flag=0;
		if(m==1)
			scanf("%s",map[1]);
		if(m==2)
			for(int i=1;i<=n;i++)
				scanf("%s",map[i]);
		if(m>=3)
		{	
			for(int i=1;i<=m;i++)
				for(int j=1;j<=n;j++)
				{
					scanf("%s",map[j]);
					for(int l=1;l<=n;l++)
						if(map[j][l]=='.') 
							tmp[j][l]='.';
				}
			for(int j=1;j<=n;j++)
				for(int l=1;l<=n;l++)
				{
					if(tmp[j][l]=='.'&&map[j][l]!='@') map[j][l]='.';
					if(tmp[j][l]!='.'&&map[j][l]!='@') map[j][l]='#';
				}					

		}
		a[1].x=1;
		a[1].y=1;
		a[1].deep=1;
		st=1;
		ed=1;
		while(st<=ed)
		{
			map[a[st].x][a[st].y]='#';
			for(int i=0;i<=3;i++)
			{
				int sx=a[st].x+dx[i],sy=a[st].y+dy[i];
				if(sx>=1&&sx<=n&&sy>=1&&sy<=n)
				{
					if(map[sx][sy]=='.')
					{
						a[++ed].deep=a[st].deep+1;
						a[ed].x=sx;
						a[ed].y=sy;
						map[sx][sy]='#';
					}
					else if(map[sx][sy]=='@')
					{
						printf("YES\n");
						flag=1;
						break;
					}
				}
			}
			if(flag) break;
			st++;
		}
		if(!flag) printf("No\n");
	} 
} 
