#include<stdio.h>
struct aa
{
	int x,y,v;
}a[22500];
char map[150][150];
int wx[]={0,0,0,1,-1},wy[]={0,1,-1,0,0};
int main()
{
	int m,n;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%s",map[i]+1);
		for(int j=1;j<=m;j++)
		{
			if(map[i][j]=='S') 
			{
				a[1].x=i;
				a[1].y=j;
				a[1].v=1;
			}
		}
	}
	int st=1,ed=1;
	while(st<=ed)
	{
		map[a[st].x][a[st].y]='#';
		bool flag=false;
		for(int i=1;i<=4;i++)
		{
				if(map[a[st].x+wx[i]][a[st].y+wy[i]]=='.')
				{
					ed++;
					a[ed].x=a[st].x+wx[i];
					a[ed].y=a[st].y+wy[i];
					a[ed].v=a[st].v+1;
					map[a[st].x+wx[i]][a[st].y+wy[i]]='#';
				}
				if(map[a[st].x+wx[i]][a[st].y+wy[i]]=='T')
				{
					printf("%d",a[st].v);
					flag=true;
					break;
				}
		}
		if(flag) break;
		st++;
	}
}
